#include "minishell.h"

int check_quotes(char *s)
{
	int i;
	int quote_s;
	int quote_d;

	i = 0;
	quote_s = 0;
	quote_d = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			quote_s++;
		if (s[i] == '\"')
			quote_d++;
		i++;
	}
	if (quote_s % 2 != 0 || quote_d % 2 != 0)
		return (1);
	return(0);
}


int check_sintax(char *s)
{
	if (!ft_strstr(s, ";"))
		return (-1);
	if (!ft_strstr(s, "\\"))
		return (-1);
	if (check_quotes(s) == 1)
		return (-1);
	return (0);
}

static char *key_to_value(int code, char **split)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	aux = NULL;
	if (code == -1)
		i = 1;
	while (split[i])
	{
		if (split[i][0] == '?')
			split[i] = ft_strjoin(ft_itoa(g_mini.exit_code), ft_substr(split[i], 1, ft_strlen(split[i])));
		else
		{
			split[i] = ft_strdup(hash_search(g_mini.env_table->nodes, split[i], ft_strlen(split[i])));
			if (split[i] == NULL)
				split[i] = ft_strdup("");
		}
		i++;
	}
	i = 0;
	while (split[i])
	{
		aux = ft_strjoin(aux, split[i]);
		i++;
	}
	return (aux);
}

void	to_variable(char **str)
{
	int		i;
	int		j;
	char	**var;

	i = 0;
	var = NULL;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '$')
			{
				var = ft_split(str[i], '$');
				if (j != 0)
					j = -1;
				break ;
			}
			j++;
		}
		if (var != NULL)
		{
			str[i] = key_to_value(j, var);
			free_matrix(var);
		}
		i++;
	}
}
