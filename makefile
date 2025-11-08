# ====== Config ======
NAME    := a.out
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
INCS    := -I .

# ここをプロジェクトの実ファイルに合わせて調整
SRCS    := push_swap.c utils.c methods.c logics.c
OBJS    := $(SRCS:.c=.o)

# ====== Rules ======
.PHONY: all clean fclean re debug test10 test100 test500

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

test2000:
	@ARGS=$$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1,11), 10))))"); \
	echo $$ARGS; \
	./$(NAME) $$ARGS | ~/Downloads/checker_Mac $$ARGS

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# デバッグビルド（必要なら -fsanitize=address を追加）
debug: CFLAGS += -g3
debug: re