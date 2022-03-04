NAME			= minishell
CC				= gcc
CFLAGS			= -Wall -Wextra -g3 #-Werror
LIBFT 			= -L ./libft -lft
RM				= rm -rf

INCLUDE 		= -I ./include/
HEADER			= ./include/minishell.h

PATH_SRC		= ./src/

PATH_MAIN		= $(addprefix 0-main/, \
		minishell.c initial_func.c signal.c \
)

PATH_PROMPT		= $(addprefix 1-prompt/, \
		prompt.c \
)

PATH_HASH		= $(addprefix 2-hash_table/, \
		create_env.c hash_search.c hash.c \
)

PATH_PARSE		= $(addprefix 3-parse/, \
		check_sintax.c expansion.c here_doc_parse_2.c here_doc_parse.c \
		check_sintax.c is_comand.c parse_input.c quotes_treat.c \
		readline_parser.c redir_parse.c swap_chars.c utils.c verify_what.c \
)

PATH_EXEC		= $(addprefix 4-exec_comand/, \
		exec_cmd.c exec_redir.c fd_to_fd.c \
)

PATH_BUILTINS	= $(addprefix 5-builtins/, \
		chdir.c export.c pwd.c unset.c \
)

PATH_MESSAGE	= $(addprefix 6-messages/, \
		errors.c \
)

PATH_UTILS		= $(addprefix utils/, \
		free_matrix.c ft_strstr.c \
)

PATH_OBJS 		= ./objs/

SRCS			= $(addprefix $(PATH_SRC), \
		$(PATH_MAIN) $(PATH_PROMPT) $(PATH_HASH) \
		$(PATH_PARSE) $(PATH_EXEC) $(PATH_BUILTINS) \
		$(PATH_MESSAGE) $(PATH_UTILS) \
)

OBJS 			= $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	rm -rf $(NAME)
	make all -C ./libft
	$(CC) $(CFLAGS) $(INCLUDE) ./objs/*/*.o $(LIBFT) -lreadline -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)0-main/
	@mkdir -p $(PATH_OBJS)1-prompt/
	@mkdir -p $(PATH_OBJS)2-hash_table/
	@mkdir -p $(PATH_OBJS)3-parse/
	@mkdir -p $(PATH_OBJS)4-exec_comand/
	@mkdir -p $(PATH_OBJS)5-builtins/
	@mkdir -p $(PATH_OBJS)6-messages/
	@mkdir -p $(PATH_OBJS)utils/
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "Cleaning objects"
	make clean -C ./libft
	@$(RM) $(PATH_OBJS)
	@echo "Done!"

fclean: clean
	make fclean -C ./libft
	@$(RM) minishell
	@echo  "Cleaning all"

re: fclean all

.PHONY: all clean fclean re push

push:clean
	rm -rf push_swap
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push
