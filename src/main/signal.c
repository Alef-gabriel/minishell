/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:08:15 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/18 22:00:15 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	abort_sig(int sig);
static void	abort_sig_child(int signal __attribute__((unused)));
static void	quit_sig_child(int sig __attribute__((unused)));

void	get_sig(void)
{
	signal(SIGINT, abort_sig);
	signal(SIGQUIT, SIG_IGN);
}

void	get_sig_child(void)
{
	signal(SIGINT, abort_sig_child);
	signal(SIGQUIT, quit_sig_child);
}

static void	abort_sig(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_mini.exit_code = 130;
	if (g_mini.on_child == TRUE)
	{
		g_mini.on_child = FALSE;
		exit(0);
	}
}

static void	abort_sig_child(int signal __attribute__((unused)))
{
	ft_putchar_fd('\n', STDERR_FILENO);
	g_mini.exit_code = 128 + signal;
}

static void	quit_sig_child(int sig __attribute__((unused)))
{
	ft_putendl_fd("Quit (core dumped)", 1);
	g_mini.exit_code = 131;
}
