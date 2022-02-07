#include "minishell.h"

char *swap_chars(char *cmd, char to_find, char to_put)
{
	int	i;

	i = 0;
/*colocar tratamento caso nao tenha sido fechado as aspas*/
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			i++;
			while (cmd[i] != '\'' && cmd[i] != '\"' && cmd[i])
			{
				if (cmd[i] == to_find)
					cmd[i] = to_put;
				i++;
			}
		}
		i++;
	}
	return (cmd);
}

char **search_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		matrix[i] = swap_chars(matrix[i], 1, ' ');
		i++;
	}
	return (matrix);
}
