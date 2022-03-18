/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:03:15 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/18 15:49:21 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	signal_type(char *s)
{
	while (*s == SPACECHAR)
		s++;
	if (*s == REDIRECT)
	{
		if (*(s + 1) == REDIRECT)
			return (2);
		else
			return (1);
	}
	else
	{
		if (*(s + 1) == REDIRECT_INPUT)
			return (2);
		else
			return (1);
	}
	return (1);
}

char	*remove_item_in_str(char *wf_cmd, int after_cnt, int before_cnt)
{
	char	*before_item;
	char	*after_item;
	char	*join;

	if (before_cnt != 0)
		before_item = ft_substr(wf_cmd, 0, before_cnt);
	else
		before_item = ft_strdup("\0");
	before_cnt = file_trima(wf_cmd + after_cnt);
	after_item = ft_substr(wf_cmd + after_cnt + before_cnt, 0,
			ft_strlen(wf_cmd + after_cnt + before_cnt));
	join = ft_strjoin(before_item, after_item);
	free(before_item);
	free(after_item);
	free(wf_cmd);
	return (join);
}

t_files	*parser(char iten, t_files *(*save)(char *, t_files *anchor, int sig))
{
	int		before;
	int		after;
	t_files	*save_file;

	before = 0;
	save_file = NULL;
	while (g_mini.commands->wf_cmd && g_mini.commands->wf_cmd[before])
	{
		after = before;
		if (g_mini.commands->wf_cmd[before] == iten)
		{
			while (g_mini.commands->wf_cmd[after]
				&& (g_mini.commands->wf_cmd[after] == iten
					|| g_mini.commands->wf_cmd[after] == SPACECHAR))
				after++;
			save_file = save(g_mini.commands->wf_cmd + after, save_file,
					signal_type(g_mini.commands->wf_cmd + before));
			g_mini.commands->wf_cmd
				= remove_item_in_str(g_mini.commands->wf_cmd, after, before);
			before = -1;
		}
		before++;
	}
	return (save_file);
}

char	**cmd_parser(char *cmd, t_node *path)
{
	int		i;
	char	**path_list;
	char	**n_cmd;

	i = 0;
	if (cmd && *cmd)
	{
		if (path == NULL)
			return (NULL);
		path_list = ft_split(path->value, ':');
		while (cmd[i] == SPACECHAR)
			i++;
		if (i == (int)ft_strlen(cmd))
			return (NULL);
		n_cmd = ft_split(cmd, SPACECHAR);
		n_cmd = path_cmds(path_list, n_cmd);
		free_matrix(path_list);
		return (n_cmd);
	}
	return (NULL);
}

char	*ft_conect(char	*first, char *mid, char *end)
{
	char	*path;
	char	*res;

	if (first == NULL)
		return (end);
	else if (!ft_strcmp(first, end))
		return (end);
	path = ft_strjoin(first, mid);
	res = ft_strjoin(path, end);
	free(path);
	return (res);
}
