/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_what.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:03:22 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/18 16:23:21 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtins(char **cmd)
{
	if (cmd)
	{
		if (!(ft_strcmp(cmd[0], "echo\0")))
			ft_echo(cmd + 1);
		else if (!(ft_strcmp(cmd[0], "cd\0")))
			cd_dir(cmd);
		else if (!(ft_strcmp(cmd[0], "env\0")))
			print_table();
		else if (!(ft_strcmp(cmd[0], "export\0")))
			export(g_mini.env_table, cmd[1]);
		else if (!(ft_strcmp(cmd[0], "pwd\0")))
			pwd_build();
		else if (!(ft_strcmp(cmd[0], "unset\0")))
			unset(g_mini.env_table, cmd[1]);
		else
			return (0);
	}
	return (1);
}
