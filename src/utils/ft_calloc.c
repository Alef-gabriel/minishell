/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:05:39 by gabriel           #+#    #+#             */
/*   Updated: 2022/02/07 01:20:40 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memset(void *mem, int c, size_t len)
{
	while (len--)
	{
		*(unsigned char *)(mem + len) = (unsigned char)(c);
	}
	return (mem);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nbytes, size_t sizemem)
{
	void	*ptr;

	ptr = malloc(nbytes * sizemem);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, (nbytes * sizemem));
	return (ptr);
}
