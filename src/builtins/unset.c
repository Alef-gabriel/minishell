/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:29:04 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 01:21:38 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	node_switch(t_node *aux, int depth_cont, t_hash *data, int index)
{
	int		i;

	i = 0;
	while (aux)
	{
		free(aux->key);
		free(aux->value);
		if (aux->next != NULL)
		{
			aux->key = ft_strdup(aux->next->key);
			aux->value = ft_strdup(aux->next->value);
			depth_cont++;
		}
		aux = aux->next;
	}
	while (i < (depth_cont - 1))
	{
		data->nodes[index] = data->nodes[index]->next;
		i++;
	}
	if (data->nodes[index]->next != NULL)
		free(data->nodes[index]->next);
	data->nodes[index]->next = NULL;
}

int	unset(t_hash *data, char *key)
{
	t_node	*aux;
	int		key_len;
	int		index;
	int		depth_cont;

	depth_cont = 0;
	key_len = ft_strlen(key);
	index = hash(key, data->size);
	aux = data->nodes[index];
	while (aux)
	{
		if (ft_memcmp(aux->key, key, key_len) == 0)
			node_switch(aux, depth_cont, data, index);
		aux = aux->next;
		depth_cont++;
	}
	return (0);
}
