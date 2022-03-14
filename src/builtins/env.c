#include "minishell.h"
//corrigir
int	print_table(t_node **nodes, int fd)
{
	int		i;

	i = 0;
	while (g_mini.env[i])
	{
		write(fd, g_mini.env[i], ft_strlen(g_mini.env[i]));
		write(fd, "\n", 1);
		i++;
	}
	return (0);
}
