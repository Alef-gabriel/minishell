/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_quotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:03:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/16 01:04:44 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(char *input, int index);
int	check_double(char *input, int index);
int	check_single(char *input, int index);

int	inspect_quotation(char *input)
{
	int	index;

	index = 0;
	while (input[index] != '\0')
	{
		if ((input[index] == '\"' || input[index] == '\'' ) && \
		input[index + 1] != '\0')
		{
			if (check_quotes(input, index))
			{
				return (1);
			}
		}
		index++;
	}
	return (0);
}

int	check_quotes(char *input, int index)
{
	if (input[index] == '\"')
	{
		return (check_double(input, index));
	}
	else if (input[index] == '\'')
	{
		return (check_single(input, index));
	}
	else
	{
		return (0);
	}
}

int	check_double(char *input, int index)
{
	int	temp_index;

	temp_index = index;
	while (input[temp_index] != '\0')
	{
		temp_index++;
		if (input[temp_index] == '\"')
		{
			return (0);
		}
	}
	print_error("unclosed quotation mark", "\' \" \'", 0);
	return (1);
}

int	check_single(char *input, int index)
{
	int	temp_index;

	temp_index = index + 1;
	while (input[temp_index] != '\0')
	{
		if (input[temp_index] == '\'')
		{
			return (0);
		}
		temp_index++;
	}
	print_error("unclosed quotation mark", "\' \' \'", 0);
	return (1);
}
