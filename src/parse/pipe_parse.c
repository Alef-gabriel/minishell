#include "minishell.h"

int pipe_parse(char *s)
{
	t_commands *save_init;
	char	**env;
	char	*local;

	save_init = g_mini.commands;
	separate_in_pipes(s);
	g_mini.commands = save_init;
	while (g_mini.commands->next != NULL)
	{
		g_mini.commands->files_redir = parser(g_mini.commands->wf_cmd, '>', &files_save, &check_redir);
		g_mini.commands->cmd = cmd_parser(g_mini.commands->wf_cmd);
		g_mini.commands = g_mini.commands->next;
	}
	g_mini.commands = save_init;
	ft_test(g_mini.commands->wf_cmd);
	//to_variable(g_mini.commands->cmd);
	/*
	char	**t;
	t = ft_split(g_mini.commands->wf_cmd, '\"');
	for (size_t i = 0; t[i]; i++)
	{
		printf("%s\n", t[i]);
	}
	*/
	/*
	local = check_path(g_mini.commands->cmd[0], g_mini.env_table->nodes);
	env = hash_to_env(g_mini.env_table->nodes);
	redir_exec(g_mini.commands);
	ft_exec(local, g_mini.commands, env);
	free_matrix(env);
	if (g_mini.cont_pipe == 0)
		fd_to_fd(g_mini.fd_in, g_mini.commands->files_redir);
	*/
	// fazer isso quando executar o comando
	// fechar os fds abertos
	while (g_mini.commands->wf_cmd != NULL)
	{
		free(g_mini.commands->wf_cmd);
		g_mini.commands->wf_cmd = NULL;
		free_matrix(g_mini.commands->cmd);
		g_mini.commands->cmd = NULL;
		g_mini.commands = g_mini.commands->next;
	}
	g_mini.commands = save_init;
	return (0);
}