/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:05:02 by algabrie          #+#    #+#             */
/*   Updated: 2021/09/14 18:05:03 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_len(int n)
{
	int	cont;

	cont = 0;
	if (n < 10 && n >= 0)
		return (cont + 1);
	if (n < 0)
	{
		if (n == -2147483648)
			n++;
		cont++;
		n = n * -1;
	}
	while (n)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

static int	negative(char *s, int n)
{
	if (n == -2147483648)
		n++;
	s[0] = '-';
	n = n * -1;
	return (n);
}

char	*ft_itoa(int n)
{
	int		size;
	int		min;
	char	*str;
	int		isneg;

	size = ft_len(n);
	min = 0;
	str = (char *)malloc(size + 1);
	if (n == -2147483648)
		min++;
	isneg = 0;
	if (n < 0)
	{
		n = negative(str, n);
		isneg++;
	}
	str[size] = 0;
	while (size - isneg)
	{
		str[size - 1] = (n % 10) + min + '0';
		min = 0;
		n = n / 10;
		size --;
	}
	return (str);
}
