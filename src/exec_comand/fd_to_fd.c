#include "minishell.h"

int	fd_to_fd(int fd_in, t_files *fd_out)
{
	if (fd_out != NULL && fd_in != 0)
	{
		while (fd_out)
		{
			ft_filecmp(fd_out->fd, fd_in);
			close(fd_out->fd);
			fd_out->fd = open(fd_out->file_name, O_RDONLY, 0644);
			fd_in = fd_out->fd;
			fd_out = fd_out->next;
		}
	}
	return(fd_in);
}
