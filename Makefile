SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
FTPATH = libft/
MLPATH = mlx_linux/
INDIR = $(FTPATH)include/
LIBFT = $(FTPATH)libft.a
MLX =$(MLPATH)libmlx.a

#################################################################
src = main.c\
	colors.c\
	bresenham.c\
	utils.c\
	parser.c\
	draw.c\
	free.c\
	movements.c\
	movements2.c\
	hook.c\
	

OBJS = ${addprefix $(OBJDIR),$(src:.c=.o)}
#################################################################
CFLAGS = #-Wall -Wextra -Werror -Ofast
LINK = -lft -lmlx -lXext -lX11 -lm
CC = gcc -g
INCPATH = -I$(INCDIR) -I$(INDIR) -I$(MLPATH)
LIBPATH = -L$(FTPATH) -L$(MLPATH)
NAME = fdf

all: ${NAME}

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

${NAME}: ${OBJS} $(LIBFT) $(MLX)
	$(CC) ${OBJS} $(LIBPATH) $(LINK) -o $(NAME)

$(LIBFT): 
	make -C $(FTPATH)

$(MLX):
	make -C $(MLPATH)

checker:
	make re -C checker_dir/
	cp checker_dir/checker .

lft:
	make -C $(FTPATH)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all libft clean fclean re
