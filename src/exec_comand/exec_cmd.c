#include "minishell.h"

static int	**creat_pipe_array(void)
{
	int		**pipes;
	int		i;

	i = 0;
	if (g_mini.cont_pipe > 0)
		g_mini.cont_pipe++;
	pipes = (int **)ft_calloc(sizeof(int *), g_mini.cont_pipe);
	while (i < g_mini.cont_pipe)
	{
		pipes[i] = (int *)ft_calloc(sizeof(int), 2);
		i++;
	}
	return (pipes);
}

void ft_exec(char *path, t_commands *cmds, char **env)
{
	int			pid;
	t_commands	*aux;
	int		piper[2];
	int		fd_in;

	fd_in = 0;
	aux = cmds;
	while (cmds->next != NULL)
	{
		if (g_mini.cont_pipe > 0)
			pipe(piper);
		if ((pid = fork()) == 0)
		{
			dup2(fd_in, STDIN_FILENO);
			close(piper[0]);
			if (g_mini.cont_pipe > 0)
				dup2(piper[1], STDOUT_FILENO);
			execve(ft_conect(path, "/", cmds->cmd[0]), cmds->cmd, env);
		}
		else
		{
			waitpid(pid, NULL, 0);
			close(piper[1]);
			fd_in = piper[0];
			cmds = cmds->next;
		}
	}
	//printf("%s", get_next_line(fd_in));
	cmds = aux;
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

char **hash_to_env(t_node **nodes)
{
	int		i;
	char	**env;
	char	*path;
	t_node	*aux;
	//the exec error is here
	i = 0;
	env = (char **)ft_calloc(sizeof(char *), 1);
	while (i < g_mini.env_table->size)
	{
		if (nodes[i] && nodes[i]->key != NULL)
		{
			aux = nodes[i];
			while (nodes[i]->next != NULL)
			{
				path = ft_conect(nodes[i]->key, "=", nodes[i]->value);
				env = append_in_matrix(env, path);
				nodes[i] = nodes[i]->next;
			}
			nodes[i] = aux;
			path = ft_conect(nodes[i]->key, "=", nodes[i]->value);
			env = append_in_matrix(env, path);
		}
		i++;
	}
	return (env);
}
