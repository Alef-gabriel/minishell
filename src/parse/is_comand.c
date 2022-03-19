/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:02:41 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/19 00:34:30 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "echo\0") || !ft_strcmp(cmd, "unset\0")
		|| !ft_strcmp(cmd, "export\0") || !ft_strcmp(cmd, "env\0")
		|| !ft_strcmp(cmd, "cd\0") || !ft_strcmp(cmd, "pwd\0"))
		return (1);
	return (0);
}

char	**path_cmds(char **path_comand, char **cmd)
{
	char	*command_which;
	int		pos;

	pos = 0;
	while (path_comand && path_comand[pos] != NULL)
	{
		if (access(cmd[0], F_OK) == 0 || is_builtins(cmd[0]))
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
	if (path_comand == NULL && (access(cmd[0], F_OK) == 0
			|| is_builtins(cmd[0])))
		return (cmd);
	error_cmd(cmd[0]);
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

void	error_cmd(char *cmd)
{
	g_mini.exit_code = 127;
	if (ft_strncmp(cmd, "/", 1) == 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	}
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	return ;
}
