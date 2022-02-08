/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:58:23 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 01:22:05 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// executar as dups caso necessario (em caso de redirect)
// criar a commat_commands, linkando todos os pipes antes
// de começar com os execs
char	*takeinput(void)
{
	char	*buffer;

	buffer = readline("MINIHELL: ");
	return (buffer);
}

int	count_cmd_len(char *s, int init)
{
	int	ret;

	ret = 0;
	while (s[init] != '|' && s[init])
	{
		ret++;
		init++;
	}
	return (ret);
}

void	separate_in_pipes(char *s)
{
	int			i;
	int			j;
	int			len;
	t_commands	*save_init;

	i = 0;
	j = 0;
	len = 0;
	save_init = g_mini.commands;
	while (s[i])
	{
		j = i;
		while (s[j] != '|' && s[j])
		{
			j++;
		}
		if (s[j] == '\0' || s[j] == '|')
		{
			if (s[j] == '|')
				g_mini.pipes++;
			len = count_cmd_len(s, i);
			g_mini.commands->wf_cmd = ft_substr(s, i, len);
			if (g_mini.commands->next == NULL)
			{
				g_mini.commands->next = (t_commands *)ft_calloc(sizeof(t_commands), 1);
			}
			g_mini.commands = g_mini.commands->next;
		}
		i = j + 1;
		if (i >= ft_strlen(s))
			break ;
	}
	g_mini.commands = save_init;
}

void	parse_input(char *s, char **env)
{
	//criar função de erro de syntax
	if (check_sintax(s) == -1)
	{
		printf ("erro de sintax funcionando\n");
		return ;
	}
	if (pipe_parse(s) == -1)
		return ;
	// verify_what_is(s);
	// if(is_comand(s))
	// 	try_to_exec(s, env);
}
