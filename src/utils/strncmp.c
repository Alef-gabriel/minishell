/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:00:11 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/01/13 14:58:37 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cmp;

	cmp = 0;
	if(s2 == NULL)
		return(1);
	while (n--)
	{
		if (s1[cmp] != s2[cmp] || s1[cmp] == '\0' || s2[cmp] == '\0')
			return (1);
		cmp++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	cmp;
	int	len;
	
	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	cmp = 0;
	if(s2 == NULL)
		return(1);
	while (len--)
	{
		if (s1[cmp] != s2[cmp] || s1[cmp] == '\0' || s2[cmp] == '\0')
			return (1);
		cmp++;
	}
	return (0);
}


