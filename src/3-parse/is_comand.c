#include "minishell.h"

char	*check_path(char *cmd, t_node **nodes)
{
	int		pos;
	char	**path_comand;
	char	*command_which;
	char	*path;

	pos = 0;
	path = hash_search(nodes, "PATH", 5);
	path_comand = ft_split(path, ':');
	while (path_comand[pos] != NULL)
	{
		command_which = ft_conect(path_comand[pos], "/", cmd);
		if (access(command_which, F_OK) == 0)
		{
			path = ft_strdup(path_comand[pos]);
			free_matrix(path_comand);
			free(command_which);
			return (path);
		}
		free(command_which);
		pos++;
	}
	free_matrix(path_comand);
	return (NULL);
}


int	is_comand(char *s)
{
	char	*cmd;
	char	**matrix;
	char	*temp;


	temp = swap_chars(s, ' ', 1);
	matrix = ft_split(temp, ' ');
	matrix = search_matrix(matrix);
	cmd = check_path(matrix[0],g_mini.env_table->nodes);
	if (cmd == NULL)
	{
		return (1);
	}
	return (0);
}
