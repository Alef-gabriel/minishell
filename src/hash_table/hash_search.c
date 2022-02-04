#include "minishell.h"

char *hash_search(t_node **nodes, char *key, int len)
{
	int	i;

	i = hash(key, g_mini.env_table->size);
	while (nodes[i] && ft_memcmp(nodes[i]->key, key, len) != 0)
		nodes[i] = nodes[i]->next;
	return (nodes[i]->value);
}

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