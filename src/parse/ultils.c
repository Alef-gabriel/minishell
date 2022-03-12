#include "minishell.h"

t_files	*file_init(char *filename)
{
	t_files	*file;

	file = (t_files *)ft_calloc(sizeof(t_files), 1);
	file->fd = 0;
	file->file_name = filename;
	file->link = 0;
	file->next = NULL;
	return (file);
}

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

t_files	*parser(char iten, t_files *(*save)(char *, t_files *anchor, int sig))
{
	int		i;
	int		j;
	char	*aux;
	t_files	*save_file;

	i = 0;
	save_file = NULL;
	while (g_mini.commands->wf_cmd[i])
	{
		j = i;
		if (g_mini.commands->wf_cmd[i] == iten)
		{
			aux = "\0";
			while (g_mini.commands->wf_cmd[j] && (g_mini.commands->wf_cmd[j] == iten || g_mini.commands->wf_cmd[j] == SPACECHAR))
				j++;
			save_file = save(g_mini.commands->wf_cmd + j, save_file, signal_type(g_mini.commands->wf_cmd + i));
			if (i != 0)
				aux = ft_substr(g_mini.commands->wf_cmd, 0, i);
			i = file_trima(g_mini.commands->wf_cmd + j);
			g_mini.commands->wf_cmd = ft_strjoin(aux, ft_substr(g_mini.commands->wf_cmd + j + i, 0, ft_strlen(g_mini.commands->wf_cmd + j + i)));
			i = -1;
		}
		i++;
	}
	return (save_file);
}

char	**cmd_parser(char *cmd)
{
	int		i;
	char	**n_cmd;
	char	*s_cmd;

	i = 0;
	while (cmd[i] && cmd[i] != REDIRECT && cmd[i] != REDIRECT_INPUT && cmd[i] != PIPE)
		i++;
	if (i == 0 && cmd[i])
		i++;
	s_cmd = ft_substr(cmd, 0, i);
	n_cmd = ft_split(s_cmd, SPACECHAR);
	free(s_cmd);
	return (n_cmd);
}

char	*ft_conect(char	*first, char *mid, char *end)
{
	char *path;
	char *res;

	if (first == NULL)
	{
		first = '\0';
		mid = '\0';
	}
	path = ft_strjoin(first, mid);
	res = ft_strjoin(path, end);
	free(path);
	return (res);
}

