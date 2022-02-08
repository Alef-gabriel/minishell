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
	create_node(table);
	while (env[i])
	{
		j = 0;
		while ((env[i][j] != '='))
			j++;
		key = ft_substr(env[i], 0, j);
		hash_index = hash(key, table->size);
		value = ft_substr(env[i], j + 1, ft_strlen(env[i]) - j + 1);
		if (table->nodes[hash_index]->key == NULL)
		{
			table->nodes[hash_index]->key = ft_strdup(key);
			table->nodes[hash_index]->value = ft_strdup(value);
		}
		else
		{
			while (table->nodes[hash_index]->next != NULL)
				table->nodes[hash_index] = table->nodes[hash_index]->next;
			table->nodes[hash_index]->next = create_new_node(key, value);
		}
		free(key);
		free(value);
		i++;
	}
	return (table);
}
