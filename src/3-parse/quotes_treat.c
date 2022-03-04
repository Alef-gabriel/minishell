#include "minishell.h"

static char	*join_matrix(char **split)
{
	char	*join;
	int		i;

	i = 0;
	join = NULL;
	while (split[i])
	{
		join = ft_strjoin(join, split[i]);
		i++;
	}
	return (join);
}

char	*treat_quotes(char *str)
{
	int		t;
	int		u;
	int		i;
	char	**split;

	u = - 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			t = str[i];
			if (u == -1)
			{
				u = t;
				str[i] = 105;
			}
			else if (u == t)
			{
				u = - 1;
				str[i] = 105;
			}
		}
		i++;
	}
	split = ft_split(str, 105);
	return (join_matrix(split));
}
