#include "minishell.h"

char	**split_swap_cmds(char *cmd)
{
	char	**matrix;
	char	*temp;

	temp = swap_chars(cmd, ' ', 1);
	matrix = ft_split(temp, ' ');
	matrix = search_matrix(matrix);
	return (matrix);
}

char	**treat_cmd(char *cmd)
{
	char	**matrix;

	matrix = split_swap_cmds(cmd);
	return (matrix);
}

int	is_builtin(char *cmd)
{
	// criar a builtin de cad um epaasar como função no if
	// else passa para o execve
	if (!(ft_strstr(cmd, "exit")))
		return (TRUE);
	if (!(ft_strstr(cmd, "cd")))
		return (TRUE);
	if (!(ft_strstr(cmd, "pwd")))
		return (TRUE);
	if (!(ft_strstr(cmd, "export")))
		return (TRUE);
	if (!(ft_strstr(cmd, "env")))
		return (TRUE);
	if (!(ft_strstr(cmd, "unset")))
		return (TRUE);
	return (FALSE);
}
