#include "minishell.h"

char **split_swap_cmds(char *cmd)
{
	char **matrix;
	char *temp;

	temp = swap_chars(cmd, ' ', 1);
	matrix = ft_split(temp, ' ');
	matrix = search_matrix(matrix);
	return (matrix);
}

char **treat_cmd(char *cmd)
{
	char **matrix;

	matrix = split_swap_cmds(cmd);
	return(matrix);
}

int	exec_builtins(char **cmd)
{
	if (!(ft_strcmp(cmd[0], "cd\0")))
		cd_dir(cmd);
	else if (!(ft_strcmp(cmd[0], "env\0")))
		print_table(g_mini.env_table->nodes);
	else if (!(ft_strcmp(cmd[0], "export\0")))
		export(g_mini.env_table, cmd[1]);
	else if (!(ft_strcmp(cmd[0], "pwd\0")))
		pwd_build();
	else if (!(ft_strcmp(cmd[0], "unset\0")))
		unset(g_mini.env_table, cmd[1]);
	else
		return(0);
	return (1);
}
