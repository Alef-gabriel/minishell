#include "minishell.h"

void	init_term(void)
{
	printf("\033[H\033[J");
}

t_commands	*init_comands(void)
{
	t_commands	*commands;

	commands = (t_commands *)ft_calloc(sizeof(t_commands), 1);
	commands->limiter = NULL;
	commands->files_redir = NULL;
	commands->cmd = NULL;
	commands->wf_cmd = NULL;
	commands->input = NULL;
	commands->next = NULL;
	return (commands);
}

void init_vars(void)
{
	g_mini.cont_pipe = 0;
	g_mini.comand = 0;
	g_mini.fd_in = 1;
	g_mini.on_child = FALSE;
	g_mini.commands = init_comands();
}
