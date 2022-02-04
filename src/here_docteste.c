# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
#define BUFFER_SIZE 1000
#define MAX_FD 51

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dst;

	dst = malloc(ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cmp;

	cmp = 0;
	if(s2 == NULL)
		return(1);
	while (n--)
	{
		if (s1[cmp] != s2[cmp] || s1[cmp] == '\0' || s2[cmp] == '\0')
			return (1);
		cmp++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	string_len;
	size_t	i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	string_len = ft_strlen(s);
	if (start > string_len)
		return (ft_strdup(""));
	if (start + len > string_len)
		len = string_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*ccat;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ccat = malloc(len1 + len2 + 1);
	if (!ccat)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ccat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ccat[i + j] = s2[j];
		j++;
	}
	ccat[i + j] = '\0';
	return (ccat);
}

char	*ft_strchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		s_len--;
	}
	return (NULL);
}

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*format_line(char **buffer, char *swap, int new_line_index)
{
	char	*line_formated;


	if (new_line_index < 0)
	{
		if (!**buffer && !swap)
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		line_formated = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (line_formated);
	}
	*buffer = ft_substr(swap, new_line_index + 1, ft_strlen(swap));
	swap[new_line_index + 1] = '\0';
	line_formated = swap;
	swap = NULL;
	return (line_formated);
}

char	*get_line(int fd, char **buffer, char *read_buffer)
{
	int		read_bytes;
	char	*swap;
	char	*find_new_line;
	int		new_line_position;

	swap = NULL;
	find_new_line = ft_strchr(*buffer, '\n');
	while (find_new_line == NULL)
	{
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (format_line(buffer, swap, -1));
		read_buffer[read_bytes] = '\0';
		swap = ft_strjoin(*buffer, read_buffer);
		ft_free(buffer);
		*buffer = swap;
		find_new_line = ft_strchr(*buffer, '\n');
	}
	swap = *buffer;
	new_line_position = 0;
	while (swap[new_line_position] != '\n')
		new_line_position++;
	return (format_line(buffer, swap, new_line_position));
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*read_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	read_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	line = get_line(fd, &buffer[fd], read_buffer);
	ft_free(&read_buffer);
	return (line);
}

int	 main(int argc, char **argv, char **envp)
{
	char *input;
	int fd;
	int i = 0;

	fd = open (argv[2], O_CREAT | O_RDONLY | O_WRONLY | O_APPEND, 0777);
	while(1)
	{
		input = readline(STDIN_FILENO);
		if(ft_strncmp(argv[1], input, ft_strlen(argv[1])) != 0)
		{
			write(fd, input, ft_strlen(input) - 1);
			write(fd, "\n", 1);
		}
		else
			break ;
	}
	return (0);
}
