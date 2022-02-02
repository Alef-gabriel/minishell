#include "minishell.h"

t_node *hash_search(t_hash *data, char *key, int len)
{
	int	i;

	i = hash(key, data->size);
	while (ft_memcmp(data->nodes[i]->key, key, len) != 0)
		data->nodes[i] = data->nodes[i]->next;
	return (data->nodes[i]);
}

void	print_table(t_hash *table)
{
	int	i;

	i = 0;
	while (i < g_mini.env_table->size && g_mini.env_table->nodes[i])
	{
		while (g_mini.env_table->nodes[i] && g_mini.env_table->nodes[i]->key != NULL)
		{
			printf("%s=%s\n", g_mini.env_table->nodes[i]->key, g_mini.env_table->nodes[i]->value);
			g_mini.env_table->nodes[i] = g_mini.env_table->nodes[i]->next;
		}
		i++;
	}
}