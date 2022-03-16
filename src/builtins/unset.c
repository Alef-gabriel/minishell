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

//aux tem que ter o poneiro next para o node depois do que tem que excluir
static void	node_switch(int depth_cont, t_hash *data, int index)
{
	int		i;
	t_node	*aux;
	t_node	*save;
	t_node	*apoio;

	i = 0;
	apoio = NULL;
	save = NULL;
	if (depth_cont > 1)
		save = data->nodes[index];
	while (i < depth_cont)
	{
		if (i + 2 == depth_cont)
			apoio = data->nodes[index];
		aux = data->nodes[index]->next;
		if (i + 1 == depth_cont)
		{
			free(data->nodes[index]->key);
			free(data->nodes[index]->value);
			free(data->nodes[index]);
			apoio->next = aux;
		}
		data->nodes[index] = aux;
		i++;
	}
	data->nodes[index] = save;
}

int	unset(t_hash *data, char *key)
{
	t_node	*aux;
	int		key_len;
	int		index;
	int		depth_cont;

	depth_cont = 1;
	key_len = ft_strlen(key);
	index = hash(key, data->size);
	aux = data->nodes[index];
	if (aux == NULL)
		return (0);
	while (aux)
	{
		if (ft_memcmp(aux->key, key, key_len) == 0)
		{
			node_switch(depth_cont, data, index);
			break ;
		}
		aux = aux->next;
		depth_cont++;
	}
	return (0);
}
