#include "minishell.h"

char	*join_matrix(char **split)
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
	free(split);
	return (join);
}

static int	quote_expansion_verify(char *quote, int expansion)
{
	int	quote_value;

	quote_value = *quote;
	if (expansion == -1)
	{
		*quote = 1;
		return (quote_value);
	}
	else if (expansion == quote_value)
		*quote = 1;
	return (-1);
}

char	*treat_quotes(char *str)
{
	int		u;
	int		i;
	char	**split;

	u = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			u = quote_expansion_verify(str + i, u);
		else if (u == -1 && str[i] == ' ')
			str[i] = SPACECHAR;
		else if (u == -1 && str[i] == '|')
			str[i] = PIPE;
		else if (u == -1 && str[i] == '<')
			str[i] = REDIRECT_INPUT;
		else if (u == -1 && str[i] == '>')
			str[i] = REDIRECT;
		i++;
	}
	split = ft_split(str, 1); // vazamento dessa split no caso de cd nulo e no caso de um cmd simples
	return (join_matrix(split));
}
