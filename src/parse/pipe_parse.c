#include "minishell.h"

int pipe_parse(char *s)
{
	t_commands *save_init;

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
	//printf("cmmand : %s\n",ft_conect("/usr/bin", "/", g_mini.commands->cmd[0]));
	//redir_exec(g_mini.commands->files_redir);
	//hash_to_env(g_mini.env_table);
	// fazer isso quando executar o comando
	while (g_mini.commands->wf_cmd != NULL)
	{
		free(g_mini.commands->wf_cmd);
		g_mini.commands->wf_cmd = NULL;
		g_mini.commands = g_mini.commands->next;
	}
	g_mini.commands = save_init;
	return (0);
}