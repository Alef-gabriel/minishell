#include "minishell.h"
//corrigir
void	print_table(t_node **nodes)
{
	int	i;
	t_node *save;

	i = 0;
	while (g_mini.env[i])
	{
		printf("%s\n", g_mini.env[i]);
		i++;
	}
}
