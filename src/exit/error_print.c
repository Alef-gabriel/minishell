/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:58:08 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/15 03:21:53 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//make int and return -1
int	file_error(char *s)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("error file: \'", 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd("\' not found", 2);
	return (-1);
}

int	arguments_error(void)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd("too many arguments", 2);
	return (-1);
}

void	print_error(char *err_msg_f, char *err_msg_s, int status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(err_msg_f, 2);
	if (status == 0)
	{
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(err_msg_s, 2);
	}
	if (status == 1)
	{
		ft_putstr_fd(err_msg_s, 2);
		ft_putendl_fd("\'", 2);
	}
}

void	print_redir(int status)
{
	if (status == 0)
	{
		print_error("syntax error near unexpected token `", "<", 1);
	}
	if (status == 1)
	{
		print_error("syntax error near unexpected token `", ">", 1);
	}
}
