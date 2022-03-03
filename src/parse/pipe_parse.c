/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:28:42 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 01:01:06 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_parse(char *s)
{
	t_commands	*save_init;
	char		**env;
	char		*local;

	save_init = g_mini.commands;
	separate_in_pipes(s);
	g_mini.commands = save_init;
	while (g_mini.commands->next != NULL)
	{
		//refazer o esquema de colacar espaço em branco colocar outra coisa
		g_mini.commands->wf_cmd = expansion(g_mini.commands->wf_cmd);
		g_mini.commands->wf_cmd = treat_quotes(g_mini.commands->wf_cmd);
		g_mini.commands->files_redir = parser(g_mini.commands->wf_cmd, '>', &files_save, &check_redir);
		g_mini.commands->cmd = cmd_parser(g_mini.commands->wf_cmd);
		g_mini.commands = g_mini.commands->next;
	}
	g_mini.commands = save_init;
	local = check_path(g_mini.commands->cmd[0], g_mini.env_table->nodes);
	env = hash_to_env(g_mini.env_table->nodes);
	redir_exec(g_mini.commands);
	ft_exec(local, g_mini.commands, env);
	free_matrix(env);
	if (g_mini.cont_pipe == 0)
		fd_to_fd(g_mini.fd_in, g_mini.commands->files_redir);
	// fazer isso quando executar o comando
	// fechar os fds abertos
	while (g_mini.commands->wf_cmd != NULL)
	{
		free(g_mini.commands->wf_cmd);
		g_mini.commands->wf_cmd = NULL;
		free_matrix(g_mini.commands->cmd);
		g_mini.commands->cmd = NULL;
		g_mini.commands = g_mini.commands->next;
	}
	g_mini.commands = save_init;
	return (0);
}
