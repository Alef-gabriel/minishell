#include "minishell.h"
//corrigir
int	print_table(t_node **nodes, int fd)
{
	int		i;
	char	*aux;

	i = 0;
	while (g_mini.env[i])
	{
		aux = ft_strjoin(g_mini.env[i], "\n");
		write(fd, aux, ft_strlen(aux));
		i++;
	}
	return (0);
}
