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

void	ft_filecmp(int	destination_fd, int fd)
{
	char	*aux;

	aux = get_next_line(fd);
	while (aux)
	{
		write(destination_fd, aux, ft_strlen(aux));
		aux = get_next_line(fd);
	}
}
//return -1 in error
int	input_to_exec(t_files *files, int *piper, t_limiter *heredoc_limiter)
{
	int		var_fd;

	if (files || heredoc_limiter)
	{
		heredoc(heredoc_limiter, piper[1]);
		while (files)
		{
			var_fd = open(files->file_name, O_RDONLY, 0644);
			if (var_fd == -1)
			{
				file_error(files->file_name);
				g_mini.exit_code = 1;
				return (g_mini.exit_code);
			}
			ft_filecmp(piper[1], var_fd);
			close(var_fd);
			files = files->next;
		}
		g_mini.fd_in = dup(piper[0]);
		close(piper[1]);
		pipe(piper);
	}
	return (0);
}
