#include "minishell.h"

int	ft_strstr(const char *str, const char *tofind)
{
	size_t	s;
	size_t	t;

	s = 0;
	t = 0;
	if (tofind[0] == '\0')
		return (1);
	while (str[s] != '\0')
	{
		while (str [s + t] == tofind[t])
		{
			if (tofind[t + 1] == '\0')
				return (0);
			t++;
		}
		t = 0;
		s++;
	}
	return (1);
}
