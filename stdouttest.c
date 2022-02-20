#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_deletcmp(char *str, int posi)
{
	while (str[posi + 1])
	{
		str[posi] = str[posi + 1];
		posi++;
	}
	str[posi] = 0;
}

int	reverse_search(char *str, char iten, int len)
{
	len = len - 1;
	while (len >= 0 && str[len] != iten)
		len--;
	return (len);
}

int main()
{
	char	go[] = {"helllo"};

	printf("%s\n",go);
	printf("%d\n",reverse_search(go, 'e', 6));
	ft_deletcmp(go, 5);
	printf("%s\n",go);
	return (0);
}