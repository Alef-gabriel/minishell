/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:49:18 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/15 02:30:10 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	print_chdir_error(char	*diretory)
{
	ft_putstr_fd("minishell: : cd: ", 2);
	ft_putstr_fd(diretory, 2);
	ft_putendl_fd(": no such file or directory", 2);
	return ;
}

int	cd_dir(char **cmd)
{
	t_node	*aux;
	t_node	*old;
	char	*diretory;
	char	dir[100];

	diretory = cmd[1];
	if (diretory == NULL)
		diretory = "/home/";
	else if (cmd[2] != NULL)
		return (arguments_error());
	if (chdir(diretory) != 0)
	{
		print_chdir_error(diretory);
		return (-1);
	}
	aux = hash_search(g_mini.env_table->nodes, "PWD", 3);
	old = hash_search(g_mini.env_table->nodes, "OLDPWD", 6);
	free(old->value);
	old->value = aux->value;
	aux->value = ft_strdup(getcwd(dir, 100));
	return (0);
}
