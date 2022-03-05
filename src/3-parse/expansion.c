#include "minishell.h"

static int	verify_quotes(char *str, int posi)
{
	int		i;
	int		expansion[2];

	i = 0;
	expansion[0] = -1;
	expansion[1] = 1;
	while (i < posi)
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (expansion[0] == -1)
			{
				expansion[0] = str[i];
				if (str[i] == '\'')
					expansion[1] = 0;
				else
					expansion[1] = 1;
			}
			else if (str[i] == expansion[0])
			{
				expansion[1] = 1;
				expansion[0] = -1;
			}
		}
		i++;
	}
	return (expansion[1]);
}

static char	*value_to_hash(char *str)
{
	char	*value;

	if (str[0] == '?')
		value = ft_strjoin(ft_itoa(g_mini.exit_code), str + 1);
	else
		value = hash_search(g_mini.env_table->nodes, str, ft_strlen(str));
	return (value);
}

char	*expansion(char *str)
{
	int		i;
	int		j;
	char	*aux;
	char	*value;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && verify_quotes(str, i))
		{
			j = i + 1;
			while (str[j] && str[j] != ' ' && str[j] != '\'' && str[j] != '\"')
				j++;
			value = ft_substr(str + i + 1, 0, (j - 1) - i);
			value = value_to_hash(value);
			aux = ft_strjoin(ft_substr(str, 0, i), value);
			str = ft_strjoin(aux, ft_substr(str, j, ft_strlen(str)));
			i = - 1;
		}
		i++;
	}
	return (str);
}
