/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdouttest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:20:07 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/08 01:20:08 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

void	test(void)
{
	exit(0);
}

int	main(void)
{
	int		fd[2];
	pid_t	pid;
	int		ft;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		test();
		ft = open("tt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		//dup(STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		write(ft, "hello guys\n", 11);
	}
	waitpid(pid, NULL, 0);
	printf("hello\n");
	return (0);
}
