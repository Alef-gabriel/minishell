/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:47:10 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/18 15:52:19 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_table(void)
{
	int	i;

	i = 0;
	while (g_mini.env[i])
	{
		ft_putendl_fd(g_mini.env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}

char	**append_in_matrix(char **array, char *str)
{
	int		index;
	char	**res;

	index = 0;
	while (array[index])
		index++;
	res = (char **)ft_calloc(sizeof(char *), index + 2);
	index = 0;
	while (array[index])
	{
		res[index] = array[index];
		index++;
	}
	free(array);
	res[index] = str;
	return (res);
}

char	**hash_to_env(t_node **nodes)
{
	int		index;
	char	**env;
	char	*path;
	t_node	*aux;

	index = 0;
	env = (char **)ft_calloc(sizeof(char *), 1);
	while (index <= g_mini.env_table->size)
	{
		aux = nodes[index];
		while (nodes[index])
		{
			path = ft_conect(nodes[index]->key, "=", nodes[index]->value);
			env = append_in_matrix(env, path);
			nodes[index] = nodes[index]->next;
		}
		nodes[index] = aux;
		index++;
	}
	return (env);
}
