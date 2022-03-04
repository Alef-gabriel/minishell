/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:29:04 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 01:21:38 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(t_hash *data, char *key)
{
	t_node	*aux;
	int		i;
	int		len;
	int		j;

	j = 0;
	i = hash(key, data->size);
	len = ft_strlen(key);
	aux = data->nodes[i];
	while (ft_memcmp(aux->key, key, len) != 0)
	{
		aux = aux->next;
		j++;
	}
	while (aux)
	{
		free(aux->key);
		free(aux->value);
		if (aux->next != NULL)
		{
			aux->key = ft_strdup(aux->next->key);
			aux->value = ft_strdup(aux->next->value);
			j++;
		}
		aux = aux->next;
	}
	len = 0;
	while (len < (j - 1))
	{
		data->nodes[i] = data->nodes[i]->next;
		len++;
	}
	if (data->nodes[i]->next != NULL)
		free(data->nodes[i]->next);
	data->nodes[i]->next = NULL;
	return (0);
}
