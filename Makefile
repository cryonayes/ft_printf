NAME	:= ft_printf
SRCS	:= src
SRC		:= $(wildcard $(SRCS)/*.c)

OBJDIR	:= objects
LIBFT	:= $(OBJDIR)/libft.a
OBJ		:= $(SRC:$(SRCS)/%.c=$(OBJDIR)/%.o)
CC		:= gcc
CFLAGS	:= -Wall -Wextra -I ./include -g

all: dirs $(NAME)

test: all
	@mv $(OBJDIR)/libftprintf.a .
	make -C printfTester/ m

$(NAME): $(LIBFT) $(OBJ)
	# $(CC) $(OBJ) $(LIBFT) -o $(NAME)
	mv $(OBJDIR)/libft.a $(OBJDIR)/libftprintf.a
	ar -rcs $(OBJDIR)/libftprintf.a $(OBJ)

$(OBJDIR)/%.o: $(SRCS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

dirs:
	@mkdir -p objects

clean:
	rm -rf $(OBJDIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

.PHONY: all libft dirs clean fclean
