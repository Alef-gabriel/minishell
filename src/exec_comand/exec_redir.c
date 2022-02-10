#include "minishell.h"

void	redir_exec(t_files *files)
{
	t_files	*save;

	save = files;
	while (files)
	{
		if (files->doc_sig == 1)
			files->fd = open(files->file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else
			files->fd = open(files->file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
		files = files->next;
	}
	files = save;
}