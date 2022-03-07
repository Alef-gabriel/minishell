/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:30:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 00:59:46 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*nodelast(t_node *node)
{
	while (node)
	{
		if (node->next == NULL)
			return (node);
		node = node->next;
	}
	return (node);
}

void	addlast(t_node **node, t_node *new)
{
	t_node	*last;

	if (node)
	{
		if (*node)
		{
			last = nodelast(*node);
			last->next = new;
		}
		else
			*node = new;
	}
}

t_hash	*env_to_hash(char **env)
{
	t_hash	*table;
	int		i;
	int		j;
	int		hash_index;
	char	*key;
	char	*value;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	table = create_hash(i);
	i = 0;
	while (env[i])
	{
		j = 0;
		while ((env[i][j] != '='))
			j++;
		key = ft_substr(env[i], 0, j);
		hash_index = hash(key, table->size);
		value = ft_substr(env[i], j + 1, ft_strlen(env[i]) - j + 1);
		addlast(&table->nodes[hash_index], create_new_node(key, value));
		i++;
	}
	return (table);
}
