/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:59:04 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/15 01:31:41 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_numeric(char *string);
void	print_exit_error(char *string);
void	clean_exit(int exit_code, char **cmd);

int	exit_shell(char *input)
{
	int		number;
	char	**cmd;

	cmd = ft_split(input, ' ');
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (cmd[1])
	{
		number = ft_atoi(cmd[1]);
		if (number < 0 || number > 255 || !is_numeric(cmd[1]))
		{
			print_exit_error(cmd[1]);
			number = 2;
		}
		clean_exit(number, cmd);
		return (1);
	}
	clean_exit(0, cmd);
	return (1);//
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

void	clean_exit(int exit_code, char **cmd)
{
	free_matrix(cmd);
	free_to_exit();
	//adicionar funçoes de free
	rl_clear_history();
	exit(exit_code);
}
