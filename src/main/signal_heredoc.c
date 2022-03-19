/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:17:13 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/19 00:02:12 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	abort_sig_heredoc(int signal __attribute__((unused)));

void	get_sig_heredoc(void)
{
	signal(SIGINT, abort_sig_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

static void	abort_sig_heredoc(int signal __attribute__((unused)))
{
	ft_putchar_fd('\n', STDERR_FILENO);
	g_mini.exit_code = 130 + signal;
}
