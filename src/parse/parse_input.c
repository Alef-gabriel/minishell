/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algabrie <alefgabrielr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:02:46 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/15 22:02:49 by algabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_cmd_len(char *s, int init)
{
	int	ret;

	ret = 0;
	while (s[init] != PIPE && s[init])
	{
		ret++;
		init++;
	}
	return (ret);
}

void	creat_commands(char *s)
{
	t_commands	*aux;
	int			i;
	int			j;

	i = 0;
	j = 0;
	g_mini.commands = init_commands();
	aux = g_mini.commands;
	while (i < ft_strlen(s) && s[i])
	{
		j = i;
		while (s[j] != PIPE && s[j])
			j++;
		if (s[j] == '\0' || s[j] == PIPE)
		{
			if (s[j] == PIPE)
				g_mini.cont_pipe++;
			aux->wf_cmd = ft_substr(s, i, count_cmd_len(s, i));
			if (aux->next == NULL)
				aux->next = init_commands();
			aux = aux->next;
		}
		i = j + 1;
	}
}

void	parse_input(char *input)
{
	char	*s;

	s = ft_strtrim(input, " ");
	if (s[0] == '\0')
	{
		return ;
	}
	if (readline_output_parser(s) == -1)
	{
		return ;
	}
	free(s);
}
