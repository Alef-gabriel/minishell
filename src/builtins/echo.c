#include "minishell.h"

void	ft_echo(char **cmd, int fd)
{
	int		i;
	int		booption;
	char	space;

	i = 0;
	space = ' ';
	booption = 0;
	if (cmd[0] && !(ft_strcmp(cmd[0], "-n\0")))
	{
		booption = 1;
		cmd = cmd + 1;
	}
	while (cmd[i])
	{
		write(fd, cmd[i], ft_strlen(cmd[i]));
		if (cmd[i + 1] != NULL)
			write(fd, &space, 1);
		i++;
	}
	if (!booption)
		write(fd, "\n", 1);
}
