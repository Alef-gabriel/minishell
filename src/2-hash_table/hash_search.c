/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:59:52 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/05 23:24:20 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*hash_search(t_node **nodes, char *key, int len)
{
	int	i;

	i = hash(key, g_mini.env_table->size);
	if (i > g_mini.env_table->size)
		return (NULL);
	while (nodes[i] && nodes[i]->key != NULL)
	{
		if (ft_memcmp(nodes[i]->key, key, len) == 0)
		{
			return(nodes[i]->value);
		}
		nodes[i] = nodes[i]->next;
	}
	return (NULL);
}

//verificar se é necessario
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
