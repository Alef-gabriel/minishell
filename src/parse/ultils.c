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

t_files	*parser(char *s, char iten, t_files *(*save)(char *, t_files *anchor, int finish, int sig))
{
	int			i;
	int			j;
	int			len;
	int			sig;
	t_files *save_file;

	i = 0;
	save_file = NULL;
	len = ft_strlen(s);
	while (i < len && s[i])
	{
		j = 0;
		if (s[i] == iten)
		{
			sig = signal_type(s + i);
			while (s[i] && (s[i] == iten || s[i] == SPACECHAR))
				i++;
			while (s[i + j] && s[i + j] != REDIRECT && s[i + j] != REDIRECT_INPUT && s[i + j] != PIPE && s[i + j] != SPACECHAR)
				j++;
			save_file = save(s + i, save_file, j, sig);
			i = i + j;
		}
		if (j == 0)
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
	if (i == 0)
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

