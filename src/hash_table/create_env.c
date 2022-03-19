/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:30:36 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/19 04:22:51 by algabrie         ###   ########.fr       */
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

static int	matrix_cont(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

t_hash	*env_to_hash(char **env)
{
	t_hash	*table;
	int		i;
	int		j;
	int		hash_index;
	char	*key;

	i = 0;
	j = 0;
	table = create_hash(matrix_cont(env));
	while (env[i])
	{
		j = 0;
		if (ft_strstr(env[i], "_WORKSPACE_"))
		{
			while ((env[i][j] != '='))
				j++;
			key = ft_substr(env[i], 0, j);
			hash_index = hash(key, table->size);
			addlast(&table->nodes[hash_index],
				create_new_node(key, ft_substr(env[i], j + 1,
						ft_strlen(env[i]) - j + 1)));
		}
		i++;
	}
	return (table);
}
