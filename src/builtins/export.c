/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:28:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/18 21:56:56 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export(t_hash *data, char *cmd)
{
	char	*key;
	char	*value;
	t_node	*search;
	int		j;

	j = 0;
	while (cmd[j] && cmd[j] != '=')
		j++;
	if (cmd[j] != '=')
		return (0);
	key = ft_substr(cmd, 0, j);
	value = ft_substr(cmd, j + 1, ft_strlen(cmd) - j);
	search = hash_search(data->nodes, key, ft_strlen(key));
	if (!search)
		addlast(&data->nodes[hash(key, data->size)], \
		create_new_node(key, value));
	else
	{
		free(key);
		free(search->value);
		search->value = value;
	}
	return (0);
}
