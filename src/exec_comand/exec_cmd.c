#include "minishell.h"

/*
void try_to_exec(char *s, char *env)
{
	char **matrix;
	int pid;
	char *cmd;
	char *temp;

	temp = swap_chars(s, ' ', 1);
	matrix = ft_split(s, ' ');
	matrix = search_matrix(matrix);
	cmd = check_access(matrix[0]);
	pid = fork();
	if (pid == 0)
		execve(cmd, matrix, env);
	waitpid(pid, NULL, 0);
	return ;
}
*/

char **append_in_matrix(char **arrey, char *str)
{
	int		i;
	char	**res;

	i = 0;
	while (arrey[i])
		i++;
	res = (char **)ft_calloc(sizeof(char *), i + 2);
	i = 0;
	while (arrey[i])
	{
		res[i] = arrey[i];
		i++;
	}
	free(arrey);
	res[i] = str;
	return (res);
}

char **hash_to_env(t_hash *table)
{
	int		i;
	char	**env;
	char	*path;

	i = 0;
	env = (char **)ft_calloc(sizeof(char *), 1);
	while (g_mini.env_table->nodes[i])
	{
		while (g_mini.env_table->nodes[i] && g_mini.env_table->nodes[i]->key != NULL)
		{
			path = ft_conect(g_mini.env_table->nodes[i]->key, "=", g_mini.env_table->nodes[i]->value);
			env = append_in_matrix(env, path);
			g_mini.env_table->nodes[i] = g_mini.env_table->nodes[i]->next;
		}
		i++;
	}
	return (env);
}
