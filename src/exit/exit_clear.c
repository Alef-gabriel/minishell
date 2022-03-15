/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:32:59 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/15 01:32:34 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_to_exit(void)
{
	int		index;
	t_node	*aux;
	t_node	**nodes;

	index = 0;
	nodes = g_mini.env_table->nodes;
	while (index <= g_mini.env_table->size)
	{
		while (nodes[index])
		{
			aux = nodes[index]->next;
			free(nodes[index]->key);
			free(nodes[index]->value);
			free(nodes[index]);
			nodes[index] = aux;
		}
		index++;
	}
	free(g_mini.env_table->nodes);
	free(g_mini.env_table);
}

void	exit_signal(void)
{
	ft_putendl_fd("exit", 1);
	rl_clear_history();
	free_to_exit();
	exit(0);
}
