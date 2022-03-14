/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:59:04 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/14 00:54:44 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_numeric(char *string);
void	print_exit_error(char *string);
void	clean_exit(int exit_code);

int	exit_shell(char **cmd)
{
	int	number;

	ft_putendl_fd("exit", STDOUT_FILENO);
	if(cmd[1])
	{
		number = ft_atoi(cmd[1]);
		if (number < 0 || number > 255 || !is_numeric(cmd[1]))
		{
			print_exit_error(cmd[1]);
			clean_exit(2);
		}
		clean_exit(number);
		return (1);
	}
	else
	{
		clean_exit(0);
		return (1);
	}
}

int	is_numeric(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (!ft_isdigit(string[index]))
			return (0);
		index++;
	}
	return (1);
}

void	print_exit_error(char *string)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(string, 2);
	ft_putendl_fd(": numeric argument required", 2);
	return ;
}

void	clean_exit(int exit_code)
{
	rl_clear_history();
	exit(exit_code);
}
