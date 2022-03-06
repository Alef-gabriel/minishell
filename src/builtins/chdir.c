/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:49:18 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/02 23:29:55 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_dir(char *local)
{
	t_node *aux;
	char	dir[100];

	if (chdir(local) != 0)
	{
		printf("error\n");
		return (-1);
	}
	aux = hash_search(g_mini.env_table->nodes, "PWD", 3);
	hash_search(g_mini.env_table->nodes, "OLDPWD", 6)->value = aux->value;
	aux->value = getcwd(dir,100);
	return (0);
}
