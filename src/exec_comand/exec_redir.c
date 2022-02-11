#include "minishell.h"

void	redir_exec(t_commands *commands)
{
	t_files	*save;
	t_commands	*aux;

	while (commands->next)
	{
		save = commands->files_redir;
		while (commands->files_redir)
		{
			if (commands->files_redir->doc_sig == 1)
				commands->files_redir->fd = open(commands->files_redir->file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
			else
				commands->files_redir->fd = open(commands->files_redir->file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
			commands->files_redir = commands->files_redir->next;
		}
		commands->files_redir = save;
		commands = commands->next;
	}
}