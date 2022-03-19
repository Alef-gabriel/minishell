/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:03:01 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/18 21:57:12 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readline_output_parser(char *s)
{
	t_commands	*save_init;
	char		*aux;
	char		*str;

	str = expansion(s);
	aux = treat_quotes(str);
	creat_commands(aux);
	free(aux);
	save_init = g_mini.commands;
	while (g_mini.commands && g_mini.commands->next != NULL)
	{
		g_mini.commands->files_redir = parser(REDIRECT, &files_save);
		g_mini.commands->limiter = heredoc_limiter();
		g_mini.commands->files_input_redir = parser(REDIRECT_INPUT, \
		&redirect_input_files);
		g_mini.commands->cmd = cmd_parser(g_mini.commands->wf_cmd, \
		hash_search(g_mini.env_table->nodes, "PATH", 4));
		if (g_mini.commands->cmd == NULL && g_mini.commands->limiter == NULL)
			save_init = commads_reconect(save_init, g_mini.commands);
		else
			g_mini.commands = g_mini.commands->next;
	}
	g_mini.commands = save_init;
	exec_commands(g_mini.commands);
}

int	exec_commands(t_commands *commands_struct)
{
	if (!commands_struct)
		return (0);
	g_mini.env = hash_to_env(g_mini.env_table->nodes);
	redir_exec(commands_struct);
	g_mini.on_child = FALSE;
	ft_exec(commands_struct);
	free_matrix(g_mini.env);
	delete_commands(commands_struct);
	return (0);
}

static void	free_files(t_files *files)
{
	t_files	*aux;

	while (files)
	{
		aux = files->next;
		free(files->file_name);
		free(files);
		files = aux;
	}
}

static void	free_limiters(t_limiter *limiter)
{
	t_limiter	*aux;

	while (limiter)
	{
		aux = limiter->next;
		free(limiter->name);
		free(limiter);
		limiter = aux;
	}
}

void	delete_commands(t_commands *commands_struct)
{
	t_commands	*aux;

	while (commands_struct)
	{
		aux = commands_struct->next;
		if (commands_struct->wf_cmd)
			free(commands_struct->wf_cmd);
		free_files(commands_struct->files_input_redir);
		free_files(commands_struct->files_redir);
		free_matrix(commands_struct->cmd);
		free_limiters(commands_struct->limiter);
		free(commands_struct);
		commands_struct = aux;
	}
}
