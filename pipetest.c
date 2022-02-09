#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
int main()
{
	int	piper[2];
	int	piper2[2];
	pid_t	cpid;
	int status;
	struct stat buf;
	char cmd[] = "/usr/bin/ls";
	char *argp[] = {"ls", "-l", NULL};
	char *argt[] = {NULL};
	int	a;

	//printf("dir : %s\n", getcwd(NULL, 0));
	pipe(piper);
	pipe(piper2);
	//a = access(cmd, F_OK);
	//printf("execve int : %d\n",a);

	cpid = fork();
	if (cpid == 0)
	{
		dup2(piper[0], STDIN_FILENO);
		dup2(piper[1], STDOUT_FILENO);
		execve(cmd, argp, argt);

	}
	else
	{
		waitpid(cpid,&status,0);
		close(piper[1]);
		cpid = fork();
		if (cpid == 0)
		{
			char cmd[] = "/usr/bin/grep";
			char *argp[] = {"grep", "p", NULL};
			char *argt[] = {NULL};
			dup2(piper[0], STDIN_FILENO);
			dup2(piper2[1], STDOUT_FILENO);
			execve(cmd, argp, argt);
		}
		else
		{
			waitpid(cpid,&status,0);
			close(piper[0]);
			cpid = fork();
			if (cpid == 0)
			{
				close(piper2[1]);
				char cmd[] = "/usr/bin/wc";
				char *argp[] = {"wc", "-l", NULL};
				char *argt[] = {NULL};
				dup2(piper2[0], STDIN_FILENO);
				execve(cmd, argp, argt);
			}
		}
	}
	return (0);
}
*/