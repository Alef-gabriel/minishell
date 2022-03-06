#include "minishell.h"

void	print_table(t_node **nodes, int size)
{
	int	i;

	i = 0;
	while (i < size && nodes[i])
	{
		while (nodes[i] && nodes[i]->key != NULL)
		{
			printf("%s=%s\n", nodes[i]->key, nodes[i]->value);
			nodes[i] = nodes[i]->next;
		}
		i++;
	}
}