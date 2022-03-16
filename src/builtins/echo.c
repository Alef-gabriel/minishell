/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:47:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/16 00:31:43 by anhigo-s         ###   ########.fr       */
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
	if (cmd[0] && (!ft_strcmp(cmd[0], "-n")))
	{
		booption = 1;
		cmd = cmd + 1;
	}
	while (cmd[i])
	{
		ft_putchar_fd(cmd[i], STDOUT_FILENO);
		if (cmd[i + 1] != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (!booption)
		write(fd, "\n", 1);
}
