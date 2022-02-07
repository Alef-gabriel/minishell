#include "minishell.h"

void	init_term(void)
{
	printf("\033[H\033[J");
}

void	init_vars(void)
{
	g_mini.pipes = 0;
	g_mini.comand = 0;
	g_mini.commands = (t_commands *)ft_calloc(sizeof(t_commands), 1);
}
