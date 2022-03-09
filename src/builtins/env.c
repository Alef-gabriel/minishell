#include "minishell.h"
//corrigir
int	print_table(t_node **nodes, int fd)
{
	int	i;

	i = 0;
	if (fd != 1)
		fd = open("temp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	while (g_mini.env[i])
	{
		write(fd, g_mini.env[i], ft_strlen(g_mini.env[i]));
		write(fd, "\n", 1);
		i++;
	}
	if (fd != 1)
	{
		close(fd);
		return (open("temp", O_RDONLY, 0644));
	}
	return (1);
}
