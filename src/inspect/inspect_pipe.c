/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 00:27:34 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/13 23:51:59 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	inspect_pipe(char *input, int index)
{
	int	temp_index;

	temp_index = index + 1;
	while (input[temp_index] == ' ' && input[temp_index] != '\0')
	{
		temp_index++;
	}
	if (input[temp_index] != '|' && input[temp_index] != '\0')
		return (0);
	else
	{
		print_error("syntax error near unexpected token `", "|", 1);
		return (1);
	}
}

int	start_with_pipe(char *input)
{
	char	*temp_input;
	char	*temp_substring;

	temp_input = ft_strtrim(input, " ");
	temp_substring = ft_strnstr(temp_input, "||", ft_strlen(temp_input));
	if (temp_substring)
	{
		free(temp_input);
		print_error("syntax error near unexpected token `", "||", 1);
		return (1);
	}
	else if (temp_input[0] == '|')
	{
		free(temp_input);
		print_error("syntax error near unexpected token `", "|", 1);
		return (1);
	}
	free(temp_input);
	return (0);
}
