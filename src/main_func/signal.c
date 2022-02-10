#include "minishell.h"

static void	abort_sig(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	//write a cmd, take ctrl c and backspace;
	write(1, "MINIHELL: ", 10);
	if (g_mini.on_child == TRUE)
		exit(0);
}

void	get_sig(void)
{
	signal(SIGINT, abort_sig);
	signal(SIGQUIT, SIG_IGN);
}