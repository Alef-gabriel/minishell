#include "minishell.h"

static void dup_in_exec(int	*piper, int fd_in, t_commands *cmds, char *path)
{
	g_mini.on_child = TRUE;
	get_sig();
	dup2(fd_in, STDIN_FILENO);
	close(piper[0]);
	if (g_mini.cont_pipe > 0 || cmds->files_redir != NULL)
		dup2(piper[1], STDOUT_FILENO);
	execve(ft_conect(path, "/", cmds->cmd[0]), cmds->cmd, g_mini.env);
}

static void	redirect_in_exec_resut(int	*piper, t_commands *cmds)
{
	g_mini.on_child = FALSE;
	g_mini.exit_code = WEXITSTATUS(g_mini.exit_tmp);
	if (g_mini.cont_pipe > 0 || cmds->files_redir != NULL || cmds->files_input_redir != NULL)
		close(piper[1]);
	unlink("temp");
	g_mini.fd_in = piper[0];
	g_mini.fd_in = fd_to_fd(g_mini.fd_in, cmds->files_redir);
	if (g_mini.cont_pipe > 0)
		g_mini.cont_pipe--;
}

int	ft_exec(char *path, t_commands *cmds)
{
	int			pid;
	t_commands	*aux;
	int			piper[2];

	g_mini.fd_in = 0;
	aux = cmds;
	if (path != NULL)
	{
		while (cmds->next != NULL)
		{
			if (redir_input_exec(cmds->files_input_redir) == -1)
				return (-1);
			if (g_mini.cont_pipe > 0 || cmds->files_redir != NULL || cmds->files_input_redir != NULL)
				pipe(piper);
			if ((pid = fork()) == 0)
				dup_in_exec(piper, g_mini.fd_in, cmds, path);
			waitpid(pid, &g_mini.exit_tmp, 0);
			redirect_in_exec_resut(piper, cmds);
			cmds = cmds->next;
		}
		cmds = aux;
	}
	return (0);
}

char	**append_in_matrix(char **arrey, char *str)
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
	t_node	*aux;

	i = 0;
	env = (char **)ft_calloc(sizeof(char *), 1);
	while (i <= g_mini.env_table->size)
	{
		aux = nodes[i];
		while (nodes[i])
		{
			path = ft_conect(nodes[i]->key, "=", nodes[i]->value);
			env = append_in_matrix(env, path);
			nodes[i] = nodes[i]->next;
		}
		nodes[i] = aux;
		i++;
	}
	return (env);
}
