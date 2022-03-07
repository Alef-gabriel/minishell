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

int	exec_builtins(char **cmd)
{
	if (!(ft_strcmp(cmd[0], "cd\0")))
		cd_dir(cmd);//rever
	else if (!(ft_strcmp(cmd[0], "env\0")))
		print_table(g_mini.env_table->nodes);
	else if (!(ft_strcmp(cmd[0], "export\0")))
		export(g_mini.env_table, cmd[1]);
	else if (!(ft_strcmp(cmd[0], "pwd\0")))
		pwd_build();
	else
		return(0);
	return (1);
}
