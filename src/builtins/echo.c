/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:47:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/16 01:07:24 by anhigo-s         ###   ########.fr       */
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
		ft_putstr_fd(cmd[i], STDIN_FILENO);
		if (cmd[i + 1] != NULL)
		{
			ft_putchar_fd(space, STDIN_FILENO);
		}
		i++;
	}
	if (!booption)
		ft_putchar_fd('\n', STDIN_FILENO);
}
