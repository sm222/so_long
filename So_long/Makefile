#gcc main.c MLX42/libmlx42.a libft/libft.a -I include -lglfw -L "/Users/$USER/.brew/opt/glfw/lib/" && ./a.out

NAME	=	so_long
LIBFT	=	libft.a
LDIR	=	libft/

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM	=	rm -f

# Sources are all .c files
SRCS	=	main.c


OBJS	=	$(SRCS:.c=.o)
all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@ $(MAKE) -C MLX42/
	@ $(MAKE) -C $(LDIR)
	$(CC) $(CFLAGS) $(SRCS) MLX42/libmlx42.a $(LDIR)$(LIBFT) -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

# Removes objects
clean:
	$(RM) $(OBJS)
	$(RM) $(LDIR)*.o

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LDIR)$(LIBFT)

# Removes objects and executables and remakes
re: fclean all