/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:57:37 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/03 00:24:53 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*create_new_node(char *key, char *value)
{
	t_node	*ret;

	ret = (t_node *)ft_calloc(sizeof(t_node), 1);
	ret->key = key;
	ret->value = value;
	ret->next = NULL;
	return (ret);
}

t_hash	*create_hash(int size)
{
	t_hash	*hash;
	int		i;

	i = 0;
	hash = (t_hash *)ft_calloc(sizeof(t_hash), 1);
	hash->size = size;
	hash->nodes = (t_node **)ft_calloc(sizeof(t_node *), hash->size + 1);
	while (i <= size)
	{
		hash->nodes[i] = NULL;
		i++;
	}
	return (hash);
}

unsigned int	hash(char *str, unsigned int len)
{
	unsigned long int	hash;
	unsigned int		i;

	hash = 5381;
	i = 0;
	while (str[i])
	{
		hash = ((hash << 5) + hash) + (str[i]);
		i++;
	}
	return (hash % len);
}

void	atribute_node(char *key, char *value, t_hash *hash, int index)
{
	hash->nodes[index]->key = ft_strdup(key);
	hash->nodes[index]->value = ft_strdup(value);
}

