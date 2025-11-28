NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I . #Makefileにincludeパスを追加する。.はカレントディレクトリ(push swapのトップ）なので、どこ階層にいる.cからもpush_swap.hを探せるようになる)
SRCS    := push_swap.c utils.c methods.c logics.c print_methods.c\
			ft_atoi.c ft_split.c radix_sort.c utils_for_radix.c \
			ft_printf/ft_printf.c ft_printf/print_any.c ft_printf/print_any2.c ft_printf/puts.c
OBJS    := $(SRCS:.c=.o)

.PHONY: all clean fclean re test2000

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# test2000:
# 	@ARGS=$$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1,11), 10))))"); \
# 	echo $$ARGS; \
# 	./$(NAME) $$ARGS | ~/Downloads/checker_linux $$ARGS

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all