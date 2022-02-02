#include "minishell.h"

int	export(t_hash *data, char *cmd)
{
	char	*key;
	char	*value;
	int		index;
	int		j;

	j = 0;
	while (cmd[j] != '=')
		j++;
	key = ft_substr(cmd, 0, j);
	index = hash(key, data->size);
	value = ft_substr(cmd, j + 1, ft_strlen(cmd) - j + 1);
	if (data->nodes[index]->key == NULL)
	{
		data->nodes[index]->key = ft_strdup(key);
		data->nodes[index]->value = ft_strdup(value);
	}
	else
	{
		while (data->nodes[index]->next != NULL)
			data->nodes[index] = data->nodes[index]->next;
		data->nodes[index]->next = create_new_node(key, value);
	}
	return (0);
}