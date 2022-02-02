#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int		fd[2];
	pid_t	pid;
	int		ft;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		ft = open("tt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		//dup(STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		write(ft, "hello guys\n", 11);
	}
	waitpid(pid,NULL,0);
	return (0);
}