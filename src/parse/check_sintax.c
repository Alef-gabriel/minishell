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

static int	quote_expacion(char *str, int posi)
{
	int		i;
	int		expancion[2];

	i = 0;
	expancion[0] = -1;
	expancion[1] = 1;
	while (i < posi)
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (expancion[0] == -1)
			{
				expancion[0] = str[i];
				if (str[i] == '\'')
					expancion[1] = 0;
				else
					expancion[1] = 1;
			}
			else if (str[i] == expancion[0])
			{
				expancion[1] = 1;
				expancion[0] = -1;
			}
		}
		i++;
	}
	return (expancion[1]);
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

void	ft_test(char *str)
{
	int		i;
	int		j;
	char	*aux;
	char	*value;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && quote_expacion(str, i))
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
	i = 0;
	int	t;
	int	u = -1;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			t = str[i];
			if (u == -1)
			{
				u = t;
				str[i] = ' ';
			}
			else if (u == t)
			{
				u = - 1;
				str[i] = ' ';
			}
		}
		i++;
	}
	printf("%s\n",str);
}
