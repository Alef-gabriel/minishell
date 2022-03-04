#include <unistd.h>
#include <stdio.h>

int	main()
{
	if (chdir("/home/dinossauro/")==0)
		printf("foi\n");
	else
		printf("error\n");
	return (0);
}