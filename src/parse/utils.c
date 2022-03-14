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

char	*remove_iten_in_str(char *wf_cmd, int after_cont, int before_cont)
{
	char	*before_iten;
	char	*after_iten;
	char	*join;

	if (before_cont != 0)
		before_iten = ft_substr(wf_cmd, 0, before_cont);
	else
		before_iten = ft_strdup("\0");
	before_cont = file_trima(wf_cmd + after_cont);
	after_iten = ft_substr(wf_cmd + after_cont + before_cont, 0,
			ft_strlen(wf_cmd + after_cont + before_cont));
	join = ft_strjoin(before_iten, after_iten);
	free(before_iten);
	free(after_iten);
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
				= remove_iten_in_str(g_mini.commands->wf_cmd, after, before);
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
