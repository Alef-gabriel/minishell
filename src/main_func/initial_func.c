/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:57:45 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 00:57:46 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_term(void)
{
	printf("\033[H\033[J");
}

void	init_vars(void)
{
	g_mini.pipes = 0;
	g_mini.comand = 0;
	g_mini.commands = (t_commands *)ft_calloc(sizeof(t_commands), 1);
}
