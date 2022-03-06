#include <unistd.h>
#include <stdio.h>

int	main()
{
	char	dir[100];

	printf("%s\n",getcwd(dir,100));
	if (chdir("/home") != 0)
		printf("error\n");
	printf("%s\n",getcwd(dir,100));
	return (0);
}