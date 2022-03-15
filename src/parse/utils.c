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

char	*remove_item_in_str(char *w_cmd, int after_cnt, int before_cnt)
{
	char	*before_item;
	char	*after_item;
	char	*join;

	if (before_cnt != 0)
		before_item = ft_substr(w_cmd, 0, before_cnt);
	else
		before_item = ft_strdup("\0");
	before_cnt = file_trima(w_cmd + after_cnt);
	after_item = ft_substr(w_cmd + after_cnt + before_cnt, 0,
			ft_strlen(w_cmd + after_cnt + before_cnt));
	join = ft_strjoin(before_item, after_item);
	free(before_item);
	free(after_item);
	free(w_cmd);
	return (join);
}

t_files	*parser(char iten, t_files *(*save)(char *, t_files *anchor, int sig))
{
	int		before;
	int		after;
	t_files	*save_file;

	before = 0;
	save_file = NULL;
	while (g_mini.commands->w_cmd && g_mini.commands->w_cmd[before])
	{
		after = before;
		if (g_mini.commands->w_cmd[before] == iten)
		{
			while (g_mini.commands->w_cmd[after]
				&& (g_mini.commands->w_cmd[after] == iten
					|| g_mini.commands->w_cmd[after] == SPACECHAR))
				after++;
			save_file = save(g_mini.commands->w_cmd + after, save_file,
					signal_type(g_mini.commands->w_cmd + before));
			g_mini.commands->w_cmd
				= remove_item_in_str(g_mini.commands->w_cmd, after, before);
			before = -1;
		}
		before++;
	}
	return (save_file);
}

char	**cmd_parser(char *cmd)
{
	int		i;
	char	**n_cmd;

	i = 0;
	if (cmd && *cmd)
	{
		while (cmd[i] == SPACECHAR)
			i++;
		if (i == ft_strlen(cmd))
			return (NULL);
		n_cmd = ft_split(cmd, SPACECHAR);
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
	path = ft_strjoin(first, mid);
	res = ft_strjoin(path, end);
	free(path);
	return (res);
}
