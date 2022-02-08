/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:16:02 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 01:16:03 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_here_doc(char *cmd)
{
	if (!ft_strstr(cmd, "<<<"))
	{
		return (-1);
	}
	if (!ft_strstr(cmd, "<<"))
	{
		return (1);
	}
	if (!ft_strstr(cmd, "<"))
	{
		return (1);
	}
	return (0);
}

