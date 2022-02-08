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
		g_mini.commands->files_here_doc = parser(g_mini.commands->wf_cmd, '<', &files_save, &check_here_doc);
		g_mini.commands->cmd = cmd_parser(g_mini.commands->wf_cmd);
		g_mini.commands = g_mini.commands->next;
	}
	g_mini.commands = save_init;
	local = check_path(g_mini.commands->cmd[0], g_mini.env_table->nodes);
	env = hash_to_env(g_mini.env_table->nodes);
	ft_exec(local, g_mini.commands->cmd, env);
	free(local);
	free_matrix(env);
	//redir_exec(g_mini.commands->files_redir);
	// fazer isso quando executar o comando
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