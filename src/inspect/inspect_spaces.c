/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:44:43 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/03/17 20:58:35 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_is_only_spaces(char *string)
{
	int	index;

	index = 0;
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
