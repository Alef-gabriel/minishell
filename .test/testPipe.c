#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

enum	e_numero
{
	child_sucesso,
	pipe_write,
	pipe_read = 0
};

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, strlen(s));
		ft_putchar_fd('\n', fd);
	}
}

// int	child(char *path, char **argv, char **envp)
// {
// 	pid_t	pid;
// 	int		fd[2];

// 	if (pipe(fd) == -1)
// 	{
// 		ft_putendl_fd("error: não criou o pipe", 2);
// 		return(1);
// 	}
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		ft_putendl_fd("erro: não criou o processo filho", 2);
// 		return(1);
// 	}
// 	if (pid == child_sucesso)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		execve(path, argv, envp);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		waitpid(pid, NULL, 0);
// 	}
// }

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)),\
	char **env)
{
	int	piper[2];
	int	piper2[2];
	pid_t	cpid;
	pid_t	cpid2;
	int status;
	struct stat buf;
	char cmd[] = "/usr/bin/ls";
	char *argp[] = {"ls", "-l", NULL};
	//char *argt[] = {NULL};
	int	a;

	//printf("dir : %s\n", getcwd(NULL, 0));
	pipe(piper);
	pipe(piper2);
	//a = access(cmd, F_OK);
	//printf("execve int : %d\n",a);

	cpid = fork();
	if (cpid == 0)
	{
		//dup2(piper[0], STDIN_FILENO);
		dup2(piper[pipe_write], STDOUT_FILENO);
		close(piper[pipe_read]);
		execve(cmd, argp, env);

	}
	close(piper[pipe_write]);
	cpid = fork();
	if (cpid == 0)
	{
		char cmd[] = "/usr/bin/wc";
		char *argp[] = {"wc", "-l", NULL};
		//char *argt[] = {NULL};
		dup2(piper[pipe_read], STDIN_FILENO);
		ft_putendl_fd("Caiu Aqui !", 2);
		execve(cmd, argp, env);
	}
	waitpid(cpid, &status, 0);
	return (0);
}
