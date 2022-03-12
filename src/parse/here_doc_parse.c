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

static t_limiter	*save_limiter(char *s, t_limiter *anchor)
{
	t_limiter	*save_limiter;
	int			finish;

	finish = file_trima(s);
	save_limiter = anchor;
	if (anchor == NULL)
	{
		anchor = (t_limiter *)malloc(sizeof(t_limiter));
		anchor->name = ft_substr(s, 0, finish);
		anchor->next = NULL;
	}
	else
	{
		while (anchor->next != NULL)
			anchor = anchor->next;
		anchor->next = (t_limiter *)malloc(sizeof(t_limiter));
		anchor->next->name = ft_substr(s, 0, finish);
		anchor->next->next = NULL;
		anchor = save_limiter;
	}
	return (anchor);
}

t_limiter	*heredoc_limiter(void)
{
	int			i;
	int			j;
	char		*aux;
	t_limiter	*limiter_list;

	i = 0;
	limiter_list = NULL;
	while (g_mini.commands->wf_cmd[i])
	{
		j = i;
		if (g_mini.commands->wf_cmd[i] == 4 && signal_type(g_mini.commands->wf_cmd + i) == 2)
		{
			aux = "\0";
			while (g_mini.commands->wf_cmd[j] && (g_mini.commands->wf_cmd[j] == 4 || g_mini.commands->wf_cmd[j] == SPACECHAR))
				j++;
			limiter_list = save_limiter(g_mini.commands->wf_cmd + j, limiter_list);
			if (i != 0)
				aux = ft_substr(g_mini.commands->wf_cmd, 0, i);
			i = file_trima(g_mini.commands->wf_cmd + j);
			g_mini.commands->wf_cmd = ft_strjoin(aux, ft_substr(g_mini.commands->wf_cmd + j + i, 0, ft_strlen(g_mini.commands->wf_cmd + j + i)));
			i = -1;
		}
		i++;
	}
	return (limiter_list);
}
