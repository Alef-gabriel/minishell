/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_quotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:03:28 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/16 01:41:12 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quotes(char *input, int index);
static int	check_double(char *input, int index);
static int	check_single(char *input, int index);
static int	is_one_quote(char *input);

int	inspect_quotation(char *input)
{
	int	index;

	if (is_one_quote(input))
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

static int	is_one_quote(char *input)
{
	int	simple_quo;
	int	double_quo;
	int	index;

	simple_quo = 0;
	double_quo = 0;
	index = 0;
	while (input[index] != '\0')
	{
		if (input[index] == '\'')
			simple_quo++;
		if (input[index] == '\"')
			double_quo++;
		index++;
	}
	if (simple_quo == 1)
		return (print_quote(simple_quotes));
	if (double_quo == 1)
		return (print_quote(double_quotes));
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
