#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	int		piper[2];
	int		fd_int;
	pid_t	cpid;
	int		i;
	int status;
	struct stat buf;
	char cmd[] = "/usr/bin/ls";
	char *argp[] = {"ls", "-l", NULL};
	char *argt[] = {NULL};

	while (*cmd != NULL)
	{
		pipe(p);
		else if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(cmd + 1) != NULL)
				dup2(p[1], 1);
			close(p[0]);
			execvp((*cmd)[0], *cmd);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			close(p[1]);
			fd_in = p[0];
			cmd++;
		}
	}
	return (0);
}
