/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:45:15 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 20:56:26 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_redirection(char *input, int index);
static int	inspect_special_char(char *input);
static int	inspect_input_redir(char *input, int index, int status);

int	inspect_redirection(char *input)
{
	int	index;

	index = 0;
	if (start_with_pipe(input))
	{
		return (1);
	}
	if (inspect_special_char(input))
	{
		return (1);
	}
	while (input[index] != '\0')
	{
		if (check_redirection(input, index))
		{
			return (1);
		}
		index++;
	}
	return (0);
}

static int	check_redirection(char *input, int index)
{
	if (ft_strchr("<|>", input[index]))
	{
		if (input[index] == '<')
		{
			return (inspect_input_redir(input, index, redir_input));
		}
		else if (input[index] == '>')
		{
			return (inspect_input_redir(input, index, redir_output));
		}
		else
		{
			return (inspect_pipe(input, index));
		}
	}
	else
	{
		return (0);
	}
}

static int	inspect_special_char(char *input)
{
	int	index;

	index = 0;
	while (input[index] != '\0')
	{
		if (ft_strchr("();*&", input[index]))
		{
			print_error("special characters should not be interpreted", "", 0);
			return (1);
		}
		index++;
	}
	return (0);
}

static int	inspect_input_redir(char *input, int index, int status)
{
	int	temp_index;

	temp_index = index + 1;
	if (input[temp_index] == '<' || input[temp_index] == '>')
		temp_index++;
	while (input[temp_index] == ' ' && input[temp_index] != '\0')
	{
		temp_index++;
	}
	if (!ft_strchr("<|>", input[temp_index]) && input[temp_index] != '\0')
	{
		return (0);
	}
	else
	{
		print_redir(status);
		return (1);
	}
}
