/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_quotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:03:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/16 01:32:26 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quotes(char *input, int index);
static int	check_double(char *input, int index);
static int	check_single(char *input, int index);
static int	count_quotes(char *input);

int	inspect_quotation(char *input)
{
	int	index;

	if (count_quotes(input))
		return (1);
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

static int	count_quotes(char *input)
{
	int	simple_quotes;
	int	double_quotes;
	int	index;

	simple_quotes = 0;
	double_quotes = 0;
	index = 0;
	while (input[index] != '\0')
	{
		if (input[index] == '\'')
			simple_quotes++;
		if (input[index] == '\"')
			double_quotes++;
		index++;
	}
	if (simple_quotes == 1)
		return (print_quote(0));
	if (double_quotes == 1)
		return (print_quote(1));
	else
		return (0);
}

static int	check_quotes(char *input, int index)
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

static int	check_double(char *input, int index)
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

static int	check_single(char *input, int index)
{
	int	temp_index;

	temp_index = index;
	while (input[temp_index] != '\0')
	{
		temp_index++;
		if (input[temp_index] == '\'')
		{
			return (0);
		}
	}
	print_error("unclosed quotation mark", "\' \' \'", 0);
	return (1);
}
