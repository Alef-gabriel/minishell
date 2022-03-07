/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:28:57 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/07 21:28:58 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export(t_hash *data, char *cmd)
{
	char	*key;
	char	*value;
	int		index;
	int		j;

	j = 0;
	while (cmd[j] && cmd[j] != '=')
		j++;
	if (cmd[j] != '=')
		return(0);
	key = ft_substr(cmd, 0, j);
	index = hash(key, data->size);
	value = ft_substr(cmd, j + 1, ft_strlen(cmd) - j);
	addlast(&data->nodes[index], create_new_node(key, value));
	return (0);
}
