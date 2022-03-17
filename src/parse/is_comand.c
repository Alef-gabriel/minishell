/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:02:41 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/17 00:38:56 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*path_cmds(char **path_comand, char **cmd)
{
	char	*command_which;
	int		pos;

	pos = 0;
	while (path_comand[pos] != NULL)
	{
		if (access(cmd[0], F_OK) == 0)
			return (ft_strdup(cmd[0]));
		command_which = ft_conect(path_comand[pos], "/", cmd[0]);
		if (access(command_which, F_OK) == 0)
		{
			free(command_which);
			command_which = ft_strdup(path_comand[pos]);
			return (command_which);
		}
		free(command_which);
		pos++;
	}
	ft_putstr_fd("Comomand not found\n", 1);
	return (NULL);
}

char	*check_path(t_commands *commands, t_node **nodes)
{
	char		**path_list;
	char		*path_cmd;
	char		*res;
	int			first_bool;
	t_node		*path;

	res = NULL;
	path = hash_search(nodes, "PATH", 5);
	if (path == NULL || commands->cmd == NULL)
		return (NULL);
	path_list = ft_split(path->value, ':');
	first_bool = 1;
	while (commands->wf_cmd)
	{
		path_cmd = path_cmds(path_list, commands->cmd);
		if (first_bool == 1)
		{
			res = path_cmd;
			first_bool = 0;
		}
		else if (path_cmd == NULL || commands->next->wf_cmd == NULL)
			res = path_cmd;
		else if (path_cmd != res && path_cmd)
			free(path_cmd);
		commands = commands->next;
	}
	free_matrix(path_list);
	return (res);
}
