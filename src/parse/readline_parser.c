#include "minishell.h"

int	readline_output_parser(char *s)
{
	t_commands *save_init;
	int			status;

	s = expansion(s);
	s = treat_quotes(s);
	save_init = g_mini.commands;
	separate_in_pipes(s);
	g_mini.commands = save_init;
	while (g_mini.commands->next != NULL)
	{
		g_mini.commands->files_redir = parser(REDIRECT, &files_save);
		g_mini.commands->limiter = heredoc_limiter();
		g_mini.commands->files_input_redir = parser(REDIRECT_INPUT, &redirect_input_files);
		g_mini.commands->cmd = cmd_parser(g_mini.commands->wf_cmd);
		g_mini.commands = g_mini.commands->next;
	}
	g_mini.commands = save_init;
	status = exec_commands(g_mini.commands);
	return (status);
}

int	exec_commands(t_commands *commands_struct)
{
	char	*local;

	if (commands_struct->limiter == NULL && commands_struct->cmd == NULL)
		return (0);
	local = check_path(commands_struct->cmd, g_mini.env_table->nodes);
	g_mini.env = hash_to_env(g_mini.env_table->nodes);
	redir_exec(commands_struct);
	g_mini.on_child = FALSE;
	if (ft_exec(local, commands_struct) == -1)
		return (-1);
	if (local)
		free(local);
	free_matrix(g_mini.env);
	delete_commands(commands_struct);
	return (0);
}

static void free_files(t_files *files)
{
	t_files	*aux;

	aux = files;
	while (aux)
	{
		aux = files->next;
		free(files->file_name);
		free(files);
		files = aux;
	}
}

void	delete_commands(t_commands *commands_struct)
{
	while (commands_struct->wf_cmd != NULL)
	{
		free(commands_struct->wf_cmd);
		commands_struct->wf_cmd = NULL;
		free_files(commands_struct->files_input_redir);
		free_files(commands_struct->files_redir);
		free_matrix(commands_struct->cmd);
		commands_struct->cmd = NULL;
		commands_struct = commands_struct->next;
	}
}