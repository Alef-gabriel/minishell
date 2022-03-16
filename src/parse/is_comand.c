/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:02:41 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/15 22:02:41 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path(char **cmd, t_node **nodes)
{
	int		pos;
	char	**path_comand;
	char	*command_which;
	t_node	*path;

	pos = 0;
	path = hash_search(nodes, "PATH", 5);
	if (path == NULL || cmd == NULL)
		return (NULL);
	path_comand = ft_split(path->value, ':');
	while (path_comand[pos] != NULL)
	{
		command_which = ft_conect(path_comand[pos], "/", cmd[0]);
		if (access(command_which, F_OK) == 0)
		{
			free(command_which);
			command_which = ft_strdup(path_comand[pos]);
			free_matrix(path_comand);
			return (command_which);
		}
		free(command_which);
		pos++;
	}
	free_matrix(path_comand);
	return (NULL);
}
