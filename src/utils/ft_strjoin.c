/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:05:40 by gabriel           #+#    #+#             */
/*   Updated: 2022/01/11 09:17:45 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		n;
	int		s;

	s = 0;
	n = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[n] != '\0')
	{	
		new[n] = s1[n];
		n++;
	}
	while (s2[s] != '\0')
	{
		new[n + s] = s2[s];
		s++;
	}
	new[n + s] = '\0';
	return (new);
}
