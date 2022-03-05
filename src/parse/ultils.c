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

static int	signal_type(char *s)
{
	while (*s == ' ')
		s++;
	if (!(ft_strstr(s, ">>")))
		return (2);
	if (!(ft_strstr(s, ">")))
		return (1);
	if (!(ft_strstr(s, "<")))
		return (1);
	if (!(ft_strstr(s, "<<")))
		return (2);
	return (0);
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
			while (s[i] && (s[i] == iten || s[i] == ' '))
				i++;
			while (s[i + j] && s[i + j] != '>' && s[i + j] != '<' && s[i + j] != '|' && s[i + j] != ' ')
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
	while (cmd[i] && cmd[i] != '>' && cmd[i] != '<' && cmd[i] != '|')
		i++;
	s_cmd = ft_substr(cmd, 0, i);
	n_cmd = ft_split(s_cmd, ' ');
	free(s_cmd);
	return (n_cmd);
}

char	*ft_conect(char	*first, char *mid, char *end)
{
	char *path;
	char *res;

	path = ft_strjoin(first, mid);
	res = ft_strjoin(path, end);
	free(path);
	return (res);
}

int	ft_matrixlen(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
