#include "minishell.h"

static int	verify_quotes(char *str, int posi)
{
	int		index;
	int		expansion[2];

	index = 0;
	expansion[0] = -1;
	expansion[1] = 1;
	while (index < posi)
	{
		if (str[index] == '\'' || str[index] == '\"')
		{
			if (expansion[0] == -1)
			{
				expansion[0] = str[index];
				if (str[index] == '\'')
					expansion[1] = 0;
				else
					expansion[1] = 1;
			}
			else if (str[index] == expansion[0])
			{
				expansion[1] = 1;
				expansion[0] = -1;
			}
		}
		index++;
	}
	return (expansion[1]);
}

static char	*value_to_hash(char *str)
{
	char	*value;
	char	*num;
	t_node	*node;

	value = NULL;
	if (str[0] == '?')
	{
		num = ft_itoa(g_mini.exit_code);
		value = ft_strjoin(num, str + 1);
		free(str);
		free(num);
		return (value);
	}
	node = hash_search(g_mini.env_table->nodes, str, ft_strlen(str));
	if (node != NULL)
		value = ft_strdup(node->value);
	free(str);
	return (value);
}

static char	*new_str(char *value, char *str, int index, int var_len)
{
	char	*res;
	char	*before;
	char	*aux;
	char	*after;

	if (value == NULL)
		value = ft_strdup(" \0");
	before = ft_substr(str, 0, index);
	aux = ft_strjoin(before, value);
	after = ft_substr(str, var_len, ft_strlen(str));
	res = ft_strjoin(aux, after);
	free(value);
	free(aux);
	free(before);
	free(str);
	free(after);
	return (res);
}

char	*expansion(char *str)
{
	int		index;
	int		var_len;
	char	*aux;
	char	*value;

	index = 0;
	aux = ft_strdup(str);
	while (aux[index])
	{
		if (aux[index] == '$' && verify_quotes(aux, index))
		{
			var_len = index + 1;
			while (aux[var_len] && aux[var_len] != ' ' && aux[var_len] != '\''
				&& aux[var_len] != '\"')
				var_len++;
			value = ft_substr(aux + index + 1, 0, (var_len - 1) - index);
			value = value_to_hash(value);
			aux = new_str(value, aux, index, var_len);
			index = -1;
		}
		index++;
	}
	return (aux);
}
