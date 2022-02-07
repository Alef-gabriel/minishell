#include "minishell.h"

int	check_quotes(char *s)
{
	int	i;
	int	quote_s;
	int	quote_d;

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
	return (0);
}


int	check_sintax(char *s)
{
	if (!ft_strstr(s, ";"))
		return (-1);
	if (!ft_strstr(s, "\\"))
		return (-1);
	if (check_quotes(s) == 1)
		return (-1);
	return (0);
}
