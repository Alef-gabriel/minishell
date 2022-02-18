/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:00:35 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/17 23:36:42 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../libft/libft.h"
# include "./struct.h"

# define TRUE 0
# define FALSE 1
# define PATH_MAX 4096

# define SIZE 255
# define BOLDGREEN		"\033[1m\033[32m"
# define BOLDWHITE		"\033[1m\033[37m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define RESET			" $ \033[0m "

extern t_minishell	g_mini;

/* Utils */
void			free_matrix(char **matrix);
int				ft_strstr(const char *str, const char *tofind);

void			init_term(void);
void			init_vars(void);

char			**append_in_matrix(char **arrey, char *str);
char			**hash_to_env(t_node **nodes);

/* Parse */
char			*takeinput(void);
void			parse_input(char *s);
int				is_comand(char *s);
int				check_sintax(char *s);
char			*check_path(char *cmd, t_node **nodes);
//char 	*swap_chars(char *, char to_find, char to_put);
char			**search_matrix(char **matrix);
void			verify_what_is(char *s);
char			**treat_cmd(char *cmd);
void			clean_matrix_redir(void);
t_files			*file_init(char *filename);
t_files			*parser(char *s, char iten, \
	t_files *(*save)(char *, t_files *anchor, int finish, int sig), \
	int (*check)(char *cmd_line));

/*pipe parsing*/
int				pipe_parse(char *s);
void			separate_in_pipes(char *s);
char			*ft_conect(char	*first, char *mid, char *end);

/*here_doc and redirect*/
int				have_pipe(char *input);
int				is_redir(char *cmd);
int				check_redir(char *cmd_line);
int				check_here_doc(char *cmd);

/*errors messages*/
void			sintax_error(char *s);

char			**cmd_parser(char *cmd);

t_files			*files_save(char *s, t_files *anchor, int finish, int sig);

/* Exec */
void			ft_exec(char *path, char **cmd, char **env);
int				export(t_hash *data, char *cmd);
int				unset(t_hash *data, char *key);

void			redir_exec(t_files *files);

/*hash*/
t_hash			*create_hash(int size);
void			create_node(t_hash *hash);
unsigned int	hash(char *str, unsigned int len);
void			atribute_node(char *key, char *value, t_hash *hash, int index);
char			*hash_search(t_node **nodes, char *key, int len);
t_hash			*env_to_hash(char **env);
t_node			*create_new_node(char *key, char *value);
void			print_table(t_node **nodes, int size);

void	get_directory(void);

#endif