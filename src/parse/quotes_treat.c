/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_treat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:02:55 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/16 13:37:32 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_matrix(char **split)
{
	char	*join;
	char	*aux;
	int		i;

	i = 0;
	join = NULL;
	while (split[i])
	{
		aux = split[i];
		join = ft_strjoin(join, aux);
		i++;
	}
	if (i == 1)
		free(split);
	else
		free_matrix(split);
	return (join);
}

static int	check_one(char *str)
{
	while (*str)
	{
		if (*str == 1)
			return (1);
		str++;
	}
	return (0);
}

static int	quote_expacion_verify(char *quote, int expancion)
{
	int	quote_value;

	quote_value = *quote;
	if (expancion == -1)
	{
		*quote = 1;
		return (quote_value);
	}
	else if (expancion == quote_value)
	{
		*quote = 1;
		return (-1);
	}
	return (expancion);
}

char	*treat_quotes(char *str)
{
	int		u;
	int		i;
	char	**split;

	u = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			u = quote_expacion_verify(str + i, u);
		else if (u == -1 && str[i] == ' ')
			str[i] = SPACECHAR;
		else if (u == -1 && str[i] == '|')
			str[i] = PIPE;
		else if (u == -1 && str[i] == '<')
			str[i] = REDIRECT_INPUT;
		else if (u == -1 && str[i] == '>')
			str[i] = REDIRECT;
		i++;
	}
	if (!check_one(str))
		return (str);
	split = ft_split(str, 1);
	free(str);
	return (join_matrix(split));
}
