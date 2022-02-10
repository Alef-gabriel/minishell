#include "minishell.h"

void	fd_to_fd(int fd_in, t_files *fd_out)
{
	char	*aux;
	char	*join;
	t_files *save;

	save = fd_out;
	if (fd_out != NULL)
	{
		while (fd_out)
		{
			join = NULL;
			aux = get_next_line(fd_in);
			while (aux)
			{
				join = ft_strjoin(join, aux);
				aux = get_next_line(fd_in);
			}
			write(fd_out->fd, join, ft_strlen(join));
			close(fd_out->fd);
			fd_out->fd = open(fd_out->file_name, O_RDONLY, 0644);
			fd_in = fd_out->fd;
			fd_out = fd_out->next;
		}
	}
	fd_out = save;
}