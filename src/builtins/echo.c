/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:47:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/19 02:57:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **cmd, int fd)
{
	int		i;
	int		booption;
	char	space;

	i = 0;
	space = ' ';
	booption = 0;
	if (cmd[0] && !(ft_strcmp(cmd[0], "-n\0")))
	{
		booption = 1;
		cmd = cmd + 1;
	}
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], fd);
		if (cmd[i + 1] != NULL)
		{
			ft_putchar_fd(space, fd);
		}
		i++;
	}
	if (!booption)
		ft_putchar_fd('\n', fd);
}
