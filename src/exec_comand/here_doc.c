/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:04:43 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/15 22:04:44 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_limiter *limiters, int fd)
{
	char	*input;

	while (limiters)
	{
		while (true)
		{
			input = readline("heredoc> ");
			if (ft_strncmp(limiters->name, input,
					ft_strlen(limiters->name)) != 0)
			{
				write(fd, input, ft_strlen(input));
				write(fd, "\n", 1);
				free(input);
			}
			else
			{
				free(input);
				break ;
			}
		}
		limiters = limiters->next;
	}
	return ;
}
