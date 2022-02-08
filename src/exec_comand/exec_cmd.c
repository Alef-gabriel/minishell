#include "minishell.h"

void ft_exec(char *path, char **cmd, char **env)
{
	int pid;

	pid = fork();
	if (pid == 0)
		execve(path, cmd, env);
	waitpid(pid, NULL, 0);
}

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

char	**hash_to_env(t_node **nodes)
{
	int		i;
	char	**env;
	char	*path;
	//the exec error is here
	i = 0;
	env = (char **)ft_calloc(sizeof(char *), 1);
	while (i < g_mini.env_table->size)
	{
		if (nodes[i] && nodes[i]->key != NULL)
		{
			while (nodes[i]->next != NULL)
			{
				path = ft_conect(nodes[i]->key, "=", nodes[i]->value);
				env = append_in_matrix(env, path);
				nodes[i] = nodes[i]->next;
			}
			path = ft_conect(nodes[i]->key, "=", nodes[i]->value);
			env = append_in_matrix(env, path);
		}
		i++;
	}
	return (env);
}
