NAME	:= libftprintf.a
SRCS	:= src
SRC		:= $(wildcard $(SRCS)/*.c)

OBJDIR	:= objects
LIBFT	:= $(OBJDIR)/libft.a
OBJ		:= $(SRC:$(SRCS)/%.c=$(OBJDIR)/%.o)
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -I ./include

all: dirs $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@mv $(OBJDIR)/libft.a libftprintf.a
	@ar -rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft

dirs:
	@mkdir -p objects

clean:
	rm -f $(OBJDIR)/*.o
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@make -C libft fclean

.PHONY: all libft dirs clean fclean
