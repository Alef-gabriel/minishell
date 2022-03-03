/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:08:49 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/03 00:00:07 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_exec(t_commands *commands)
{
	t_files		*save;
	// t_commands	*aux;

	while (commands->next)
	{
		save = commands->files_redir;
		while (commands->files_redir)
		{
			if (commands->files_redir->doc_sig == 1)
				commands->files_redir->fd = open(commands->files_redir->file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
			else
				commands->files_redir->fd = open(commands->files_redir->file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
			commands->files_redir = commands->files_redir->next;
		}
		commands->files_redir = save;
		commands = commands->next;
	}
}
