/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:04:43 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/18 23:56:40 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_heredoc_error(char *limiter);
static int		inspect_heredoc(char *limiter, char *input, int fd);

void	heredoc(t_limiter *limiters, int fd)
{
	char	*input;

	while (limiters)
	{
		while (true)
		{
			get_sig_heredoc();
			input = readline("heredoc> ");
			if (input == NULL)
			{
				print_heredoc_error(limiters->name);
				break ;
			}
			else if (inspect_heredoc(limiters->name, input, fd))
			{
				free(input);
				break ;
			}
		}
		limiters = limiters->next;
	}
	return ;
}

static int	inspect_heredoc(char *limiter, char *input, int fd)
{
	if (ft_strncmp(limiter, input, ft_strlen(limiter)))
	{
		ft_putendl_fd(input, fd);
		free(input);
		return (0);
	}
	return (1);
}

static void	print_heredoc_error(char *limiter)
{
	ft_putstr_fd("minishell: warning: here-document ", STDERR_FILENO);
	ft_putstr_fd("delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(limiter, STDERR_FILENO);
	ft_putendl_fd("'))", STDERR_FILENO);
	g_mini.exit_code = 0;
	return ;
}
