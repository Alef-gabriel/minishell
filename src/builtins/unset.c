/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:29:04 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/19 04:54:40 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	node_switch(int depth_cont, t_hash *data, int index);
static void	free_unset(t_hash *node, int index);

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

static void	node_switch(int depth_cont, t_hash *data, int index)
{
	t_node	*aux;
	t_node	*save;
	t_node	*temp;
	int		i;

	temp = NULL;
	save = NULL;
	i = 0;
	if (depth_cont > 1)
		save = data->nodes[index];
	while (i < depth_cont)
	{
		if (i + 2 == depth_cont)
			temp = data->nodes[index];
		aux = data->nodes[index]->next;
		if (i + 1 == depth_cont)
		{
			free_unset(data, index);
			if (temp)
				temp->next = aux;
		}
		data->nodes[index] = aux;
		i++;
	}
	data->nodes[index] = save;
}

static void	free_unset(t_hash *node, int index)
{
	free(node->nodes[index]->key);
	node->nodes[index]->key = NULL;
	free(node->nodes[index]->value);
	node->nodes[index]->value = NULL;
	free(node->nodes[index]);
	node->nodes[index] = NULL;
	return ;
}
