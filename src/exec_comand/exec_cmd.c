#include "minishell.h"

static void	dup_in_exec(int	*piper, int fd_in, t_commands *cmds, char *path)
{
	g_mini.on_child = TRUE;
	get_sig();
	dup2(fd_in, STDIN_FILENO);
	if (g_mini.cont_pipe > 0 || cmds->files_redir != NULL)
	{
		close(piper[0]);
		dup2(piper[1], STDOUT_FILENO);
	}
	execve(ft_conect(path, "/", cmds->cmd[0]), cmds->cmd, g_mini.env);
}

static void	redirect_in_exec_resut(int	*piper, t_commands *cmds)
{
	g_mini.fd_in = piper[0];
	g_mini.on_child = FALSE;
	g_mini.exit_code = WEXITSTATUS(g_mini.exit_tmp);
	if (g_mini.cont_pipe > 0 || cmds->files_redir != NULL
		|| cmds->files_input_redir != NULL)
		close(piper[1]);
	g_mini.fd_in = fd_to_fd(g_mini.fd_in, cmds->files_redir);
	if (g_mini.cont_pipe > 0)
		g_mini.cont_pipe--;
}

int	ft_exec(char *path, t_commands *cmds)
{
	pid_t		pid;
	t_commands	*aux;
	int			piper[2];

	g_mini.fd_in = 0;
	aux = cmds;
	while (cmds->next != NULL)
	{
		if (g_mini.cont_pipe > 0 || cmds->files_redir
			|| cmds->files_input_redir || cmds->limiter)
			pipe(piper);
		if (input_to_exec(cmds->files_input_redir, piper, cmds->limiter) == 1)
			return (1);
		if (exec_builtins(cmds->cmd, cmds->files_redir, piper) == 0)
		{
			pid = fork();
			if (pid == 0)
				dup_in_exec(piper, g_mini.fd_in, cmds, path);
			waitpid(pid, &g_mini.exit_tmp, 0);
		}
		redirect_in_exec_resut(piper, cmds);
		cmds = cmds->next;
	}
	cmds = aux;
	return (0);
}

char	**append_in_matrix(char **array, char *str)
{
	int		index;
	char	**res;

	index = 0;
	while (array[index])
		index++;
	res = (char **)ft_calloc(sizeof(char *), index + 2);
	index = 0;
	while (array[index])
	{
		res[index] = array[index];
		index++;
	}
	free(array);
	res[index] = str;
	return (res);
}

char	**hash_to_env(t_node **nodes)
{
	int		index;
	char	**env;
	char	*path;
	t_node	*aux;

	index = 0;
	env = (char **)ft_calloc(sizeof(char *), 1);
	while (index <= g_mini.env_table->size)
	{
		aux = nodes[index];
		while (nodes[index])
		{
			path = ft_conect(nodes[index]->key, "=", nodes[index]->value);
			env = append_in_matrix(env, path);
			nodes[index] = nodes[index]->next;
		}
		nodes[index] = aux;
		index++;
	}
	return (env);
}
