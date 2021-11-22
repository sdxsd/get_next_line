CC = clang
CFLAGS = -Wall -Wextra -Werror -o
NAME = get_next_line.a
CFILES = \
	get_next_line.c \
	get_next_line_utils.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@ar -rcs $(NAME) $?
	@echo "GET_NEXT_LINE COMPILED"

%.o: %.c
	@$(CC) $(CFLAGS) -c $<
	@echo "COMPILED: " $<

re: fclean all

fclean: clean
	@rm -f $(NAME)
	@echo "FULLY CLEANED"

clean:
	@rm -f $(OFILES) a.out
	@echo "CLEANED UP"
