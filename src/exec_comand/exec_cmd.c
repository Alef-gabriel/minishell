/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:04:27 by algabrie          #+#    #+#             */
/*   Updated: 2022/03/19 02:46:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_in_exec(int	*piper, int fd_in, t_commands *cmds)
{
	g_mini.on_child = TRUE;
	dup2(fd_in, STDIN_FILENO);
	if (g_mini.cont_pipe > 0 || cmds->files_redir != NULL)
	{
		close(piper[0]);
		dup2(piper[1], STDOUT_FILENO);
	}
	execve(cmds->cmd[0], cmds->cmd, g_mini.env);
}

static void	redirect_in_exec_resut(int *piper, t_commands *cmds)
{
	g_mini.fd_in = piper[0];
	g_mini.on_child = FALSE;
	if (g_mini.cont_pipe > 0 || cmds->files_redir != NULL
		|| cmds->files_input_redir != NULL)
		close(piper[1]);
	g_mini.fd_in = fd_to_fd(g_mini.fd_in, cmds->files_redir);
	if (g_mini.cont_pipe > 0)
		g_mini.cont_pipe--;
}

void	start_child(t_commands *cmds, int piper[2])
{
	pid_t	pid;

	get_sig_child();
	pid = fork();
	if (pid == 0)
		dup_in_exec(piper, g_mini.fd_in, cmds);
	waitpid(pid, &g_mini.exit_tmp, 0);
	if (WIFEXITED(g_mini.exit_tmp))
		g_mini.exit_code = WEXITSTATUS(g_mini.exit_tmp);
}

void	ft_exec(t_commands *cmds)
{
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
			return ;
		if (exec_builtins(cmds->cmd, piper[1]) == 0)
		{
			start_child(cmds, piper);
		}
		redirect_in_exec_resut(piper, cmds);
		cmds = cmds->next;
	}
	cmds = aux;
}
