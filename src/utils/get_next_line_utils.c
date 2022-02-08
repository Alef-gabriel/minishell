/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:48:09 by algabrie          #+#    #+#             */
/*   Updated: 2021/09/29 23:55:21 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_delete(char **buf)
{
	int		i;

	i = 0;
	if (*buf)
	{
		while ((*buf)[i])
			(*buf)[i++] = 0;
		free(*buf);
		*buf = NULL;
	}
}

int	ft_buf_verify(char *buf)
{
	if (*buf)
		return (BUFFER_SIZE);
	return (0);
}
