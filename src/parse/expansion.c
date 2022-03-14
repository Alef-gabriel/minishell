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
	t_node	*node;

	if (str[0] == '?')
		value = ft_strjoin(ft_itoa(g_mini.exit_code), str + 1);
	else
	{
		node = hash_search(g_mini.env_table->nodes, str, ft_strlen(str));
		if (node == NULL)
			return ("\0");
		value = node->value;
	}
	return (value);
}

char	*expansion(char *str)
{
	int		index;
	int		j;
	char	*aux;
	char	*value;

	index = 0;
	while (str[index])
	{
		if (str[index] == '$' && verify_quotes(str, index))
		{
			j = index + 1;
			while (str[j] && str[j] != ' ' && str[j] != '\'' && str[j] != '\"')
				j++;
			value = ft_substr(str + index + 1, 0, (j - 1) - index);
			value = value_to_hash(value);
			aux = ft_strjoin(ft_substr(str, 0, index), value);
			value = ft_substr(str, j, ft_strlen(str));
			if (!(ft_memcmp(value, "\2", ft_strlen(value))))
				value = "\0";
			str = ft_strjoin(aux, value);
			index = -1;
		}
		index++;
	}
	return (str);
}
