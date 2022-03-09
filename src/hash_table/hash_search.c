/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:59:52 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 00:59:53 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*hash_search(t_node **nodes, char *key, int len)
{
	t_node	*save;
	t_node	*aux;
	int		i;

	i = hash(key, g_mini.env_table->size);
	if (i > g_mini.env_table->size)
		return (NULL);
	save = nodes[i];
	while (nodes[i] && nodes[i]->key != NULL)
	{
		if (ft_memcmp(nodes[i]->key, key, len) == 0)
		{
			aux = nodes[i];
			nodes[i] = save;
			return(aux);
		}
		nodes[i] = nodes[i]->next;
	}
	nodes[i] = save;
	return (NULL);
}
