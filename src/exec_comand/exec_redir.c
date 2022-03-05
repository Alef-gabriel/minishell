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
	char	*join;
	char	*aux;

	join = NULL;
	aux = get_next_line(fd);
	while (aux)
	{
		join = ft_strjoin(join, aux);
		aux = get_next_line(fd);
	}
	write(destination_fd, join, ft_strlen(join));
}

int	redir_input_exec(t_files *files)
{
	int		fd;
	int		var_fd;

	fd = g_mini.fd_in;
	if (files != NULL)
	{
		fd = open("temp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (g_mini.fd_in != 0)
		{
			ft_filecmp(fd, g_mini.fd_in);
			close(g_mini.fd_in);
		}
		while (files)
		{
			var_fd = open(files->file_name, O_RDONLY, 0644);
			if (var_fd == -1)
				file_error(files->file_name);
			ft_filecmp(fd, var_fd);
			close(var_fd);
			files = files->next;
		}
		close(fd);
		fd = open("temp", O_RDONLY, 0644);
	}
	return (fd);
}
