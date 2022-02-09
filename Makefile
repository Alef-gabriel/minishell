NAME = minishell

CC = gcc
CFLAGS = -g3 -Wall#-Werror

RM = rm -rf

INCLUDE = -I ./include/

PATH_SRC = ./src/
PATH_UTILS = $(PATH_SRC)utils/
PATH_HASH = $(PATH_SRC)hash_table/
PATH_MAIN = $(PATH_SRC)main_func/
PATH_MESSAGE = $(PATH_SRC)messages/
PATH_PARSE = $(PATH_SRC)parse/
PATH_EXEC = $(PATH_SRC)exec_comand/
PATH_BUILTINS = $(PATH_SRC)builtins/
PATH_OBJS = ./objs/

SRCS = $(PATH_MAIN)minishell.c $(PATH_MAIN)initial_func.c\
		$(PATH_PARSE)is_comand.c $(PATH_PARSE)swap_chars.c $(PATH_PARSE)verify_what.c\
		$(PATH_PARSE)parse_input.c $(PATH_PARSE)pipe_parse.c $(PATH_PARSE)redir_parse.c\
		$(PATH_PARSE)check_sintax.c $(PATH_PARSE)here_doc_parse.c  $(PATH_PARSE)here_doc_parse_2.c\
		$(PATH_MESSAGE)errors.c\
		$(PATH_EXEC)exec_cmd.c $(PATH_EXEC)exec_redir.c\
		$(PATH_HASH)hash.c $(PATH_HASH)create_env.c $(PATH_HASH)hash_search.c\
		$(PATH_UTILS)strlen.c $(PATH_UTILS)strncmp.c $(PATH_UTILS)ft_split.c\
		$(PATH_UTILS)ft_strjoin.c $(PATH_UTILS)free_matrix.c $(PATH_UTILS)strnstr.c\
		$(PATH_UTILS)ft_calloc.c $(PATH_UTILS)ft_strdup.c $(PATH_UTILS)ft_strlcpy.c\
		$(PATH_UTILS)ft_substr.c $(PATH_UTILS)ft_memcmp.c\
		$(PATH_UTILS)ft_strtrim.c $(PATH_UTILS)ft_putendl_fd.c \
		$(PATH_BUILTINS)export.c $(PATH_BUILTINS)unset.c $(PATH_BUILTINS)pwd.c \
		$(PATH_PARSE)ultils.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) ./objs/*/*.o -o $(NAME) -lreadline

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)exec_comand/
	@mkdir -p $(PATH_OBJS)hash_table/
	@mkdir -p $(PATH_OBJS)main_func/
	@mkdir -p $(PATH_OBJS)messages/
	@mkdir -p $(PATH_OBJS)parse/
	@mkdir -p $(PATH_OBJS)builtins/
	@mkdir -p $(PATH_OBJS)utils/
	$(CC) $(CFLAGS) $(INCLUDE) -I. -c $< -o $@ -lreadline

clean:
	@echo "\033[1;33mCleaning objects\033[0m"
	@$(RM) $(PATH_OBJS)
	@echo "\033[1;32mDone!\033[0m"

fclean: clean
	@$(RM) minishell
	@echo  "\033[1;33mCleaning all\033[0m"

re: fclean all

.PHONY: all clean fclean re push

push:clean
	rm -rf push_swap
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push