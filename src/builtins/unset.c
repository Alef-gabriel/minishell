#include "minishell.h"

int	unset(t_hash *data, char *key)
{
	int		i;
	int		len;
	int		j;
	t_node	*aux;

	j = 0;
	i = hash(key, data->size);
	len = ft_strlen(key);
	aux = data->nodes[i];
	while (ft_memcmp(aux->key, key, len) != 0)
	{
		aux = aux->next;
		j++;
	}
	while (aux)
	{
		free(aux->key);
		free(aux->value);
		if (aux->next != NULL)
		{
			aux->key = ft_strdup(aux->next->key);
			aux->value = ft_strdup(aux->next->value);
			j++;
		}
		aux = aux->next;
	}
	len = 0;
	while (len < (j - 1))
	{
		data->nodes[i] = data->nodes[i]->next;
		len++;
	}
	if (data->nodes[i]->next != NULL)
		free(data->nodes[i]->next);
	data->nodes[i]->next = NULL;
	return (0);
}
