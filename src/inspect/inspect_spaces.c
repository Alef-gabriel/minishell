/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:44:43 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/18 17:06:33 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	start_with_quotes(char *string);

int	str_is_only_spaces(char *string)
{
	int	index;

	index = 0;
	if (start_with_quotes(string))
		return (1);
	while (string[index] != '\0')
	{
		if (!ft_strchr(" 	", string[index]))
		{
			return (0);
		}
		index++;
	}
	return (1);
}

int	start_with_quotes(char *string)
{
	if (ft_strncmp(string, "\'\'", 2) == 0)
	{
		error_cmd(" ");
		return (1);
	}
	else if (ft_strncmp(string, "\"\"", 2) == 0)
	{
		error_cmd(" ");
		return (1);
	}
	else
	{
		return (0);
	}
}
