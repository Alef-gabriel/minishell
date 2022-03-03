#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	int		p[2];
	int		fd_int;
	pid_t	pid;
	int		i;
	int status;
	struct stat buf;

	pipe(p);
	if (pid == 0)
	{
		close(p[0]);
		dup2(p[1], 1);
		write(1, "hello\n",6);
	}
	else
	{
		wait(NULL);
		close(p[1]);
	}
	return (0);
}
