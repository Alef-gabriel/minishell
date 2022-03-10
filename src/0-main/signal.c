#include "minishell.h"

//write a cmd, take ctrl c and backspace;
static void	abort_sig(int sig __attribute__((unused)))
{
	ft_putchar_fd('\n', 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	if (g_mini.on_child == TRUE)
	{
		g_mini.on_child = FALSE;
		exit(0);
	}
}

void	get_sig(void)
{
	signal(SIGINT, abort_sig);
	signal(SIGQUIT, SIG_IGN);
}
