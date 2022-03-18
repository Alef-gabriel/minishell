/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:58:08 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/18 01:51:51 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_error(char *s)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("error file: \'", STDERR_FILENO);
	ft_putstr_fd(s, 2);
	ft_putendl_fd("\' not found", STDERR_FILENO);
	return (-1);
}

void	print_error(char *err_msg_f, char *err_msg_s, int status)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(err_msg_f, STDERR_FILENO);
	if (status == 0)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(err_msg_s, STDERR_FILENO);
	}
	if (status == 1)
	{
		ft_putstr_fd(err_msg_s, STDERR_FILENO);
		ft_putendl_fd("\'", STDERR_FILENO);
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

int	print_quote(int status)
{
	if (status == 0)
	{
		print_error("unclosed quotation mark", "\' \' \'", 0);
		return (1);
	}
	print_error("unclosed quotation mark", "\' \" \'", 0);
	return (1);
}
