/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:17:14 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/14 00:19:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_inspect(char *input)
{
	if (input == NULL)
	{
		//adicionar funções de free
		exit_signal();
	}
	add_history(input);
	if (inspect_quotation(input) && inspect_redirection(input))
	{
		g_mini.exit_code = 2;
		return (1);
	}
	return (0);
}
