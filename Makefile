# Compiler flags
CC      = gcc

CFLAGS      = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = libft

# Source files
SRC_FILES   = ft_printf.c			\
ft_int_putchar_fd.c   				\
ft_int_putstr_fd.c                  \
ft_int_putnbr_fd.c                  \
ft_intohex.c                        \
ft_numlen.c                         \
ft_voidtohex.c                      \

# Object files
OBJ_FILES   = $(SRC_FILES:.c=.o)

# Library name
LIBFT_NAME  = libft.a
PRINTF_NAME = libftprintf.a

# Targets
all:        $(PRINTF_NAME)
            
$(PRINTF_NAME): $(OBJ_FILES) 
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT_NAME) $(PRINTF_NAME)
	ar rcs $(PRINTF_NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:      
	rm -f $(OBJ_FILES)
	make -C ./libft clean

fclean:     clean 
	rm -f $(PRINTF_NAMENAME)
	make -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY:     all clean fclean re
