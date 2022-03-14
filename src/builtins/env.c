/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:47:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/14 02:34:20 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_table(t_node **nodes, int fd)
{
//corrigir ordem das variaveis
	int	i;

	i = 0;
	while (g_mini.env[i])
	{
		write(fd, g_mini.env[i], ft_strlen(g_mini.env[i]));
		write(fd, "\n", 1);
		i++;
	}
	return (0);
}
