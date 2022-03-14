#include "minishell.h"

int	exec_builtins(char **cmd, t_files *redirect, int *piper)
{
	int	fd;

	fd = 1;
	if (cmd)
	{
		if (g_mini.cont_pipe > 0 || redirect != NULL)
			fd = piper[1];
		if (!(ft_strcmp(cmd[0], "echo\0")))
			ft_echo(cmd + 1, fd);
		else if (!(ft_strcmp(cmd[0], "cd\0")))
			cd_dir(cmd);
		else if (!(ft_strcmp(cmd[0], "exit\0")))
			exit_shell(cmd);
		else if (!(ft_strcmp(cmd[0], "env\0")))
			print_table(g_mini.env_table->nodes, fd);
		else if (!(ft_strcmp(cmd[0], "export\0")))
			export(g_mini.env_table, cmd[1]);
		else if (!(ft_strcmp(cmd[0], "pwd\0")))
			pwd_build(fd);
		else if (!(ft_strcmp(cmd[0], "unset\0")))
			unset(g_mini.env_table, cmd[1]);
		else
			return(0);
	}
	return (1);
}
