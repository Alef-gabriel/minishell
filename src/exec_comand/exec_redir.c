/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:08:49 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/07 21:08:50 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_exec(t_files *files)
{
	while (files)
	{
		if (files->doc_sig == 1)
			files->fd = open(files->file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else
			files->fd = open(files->file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
		files = files->next;
	}
}
