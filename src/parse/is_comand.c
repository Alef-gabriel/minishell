/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:02:41 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/17 18:37:08 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**path_cmds(char **path_comand, char **cmd)
{
	char	*command_which;
	int		pos;

	pos = 0;
	while (path_comand[pos] != NULL)
	{
		if (access(cmd[0], F_OK) == 0)
			return (cmd);
		command_which = ft_conect(path_comand[pos], "/", cmd[0]);
		if (access(command_which, F_OK) == 0)
		{
			free(cmd[0]);
			cmd[0] = command_which;
			return (cmd);
		}
		free(command_which);
		pos++;
	}
	ft_putstr_fd("Comomand not found\n", 1);
	free_matrix(cmd);
	return (NULL);
}

t_commands	*commads_reconect(t_commands *save, t_commands *current)
{
	t_commands	*aux;

	g_mini.cont_pipe--;
	aux = current->next;
	if (!aux)
		aux = NULL;
	current->next = NULL;
	delete_commands(save);
	g_mini.commands = aux;
	return (aux);
}
