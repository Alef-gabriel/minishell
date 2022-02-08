/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_parse_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:58:14 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 00:58:15 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void here_doc_save_limiter(char *cmd, int init, int end)
{
	t_limiter *ini;

	if (g_mini.here_doc->limiter == NULL)
	{
		g_mini.here_doc->limiter = (t_limiter *)ft_calloc(sizeof(t_limiter), 1);
		ini = g_mini.here_doc->limiter;
	}
	else
	{
		ini = g_mini.here_doc->limiter;
		while (g_mini.here_doc->limiter->next != NULL)
		{
			g_mini.here_doc->limiter = g_mini.here_doc->limiter->next;
		}
		if (g_mini.here_doc->limiter->next == NULL)
		{
			g_mini.here_doc->limiter->next = (t_limiter *)ft_calloc(sizeof(t_limiter), 1);
			g_mini.here_doc->limiter->next->next = NULL;
			g_mini.here_doc->limiter = g_mini.here_doc->limiter->next;
		}
	}
	g_mini.here_doc->limiter->name = ft_substr(cmd, init, end);
	g_mini.here_doc->limiter = ini;
}
*/