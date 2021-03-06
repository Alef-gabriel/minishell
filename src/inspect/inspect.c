/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:17:14 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/18 01:17:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_inspect(char *input)
{
	if (input == NULL)
	{
		exit_signal();
	}
	if (!(ft_strncmp(input, "exit ", 4)) || (!ft_strcmp(input, "exit")))
	{
		exit_shell(input);
	}
	add_history(input);
	if (str_is_only_spaces(input))
		return (1);
	if (inspect_quotation(input) || inspect_redirection(input))
	{
		g_mini.exit_code = 2;
		return (1);
	}
	return (0);
}
