#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *input;
	char *s;
	int i = 0;
	int j = 0;

	init_vars();
	// init_term();
	g_mini.env_table = env_to_hash(envp);
	while (1)
	{
		input = takeinput();
		if (!ft_strncmp("exit", input, 4))
			exit(0);
		s = ft_strtrim(input, " ");
		if(s[0] != '\0')
			parse_input(s, envp);
		free(s);
		free(input);
		g_mini.pipes = 0;
	}
	return(0);
}

