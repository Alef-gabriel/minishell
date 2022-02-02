/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:50:14 by gabriel           #+#    #+#             */
/*   Updated: 2022/01/17 08:59:45 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start > i)
		return (ft_strdup(""));
	i = ft_strlen(s + start);
	if (len > i)
		len = ft_strlen(s + start);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
