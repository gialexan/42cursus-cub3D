# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 15:43:13 by gialexan          #+#    #+#              #
#    Updated: 2023/04/28 10:33:08 by gialexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memmove.c ft_strlcat.c ft_strtrim.c \
ft_get_next_line.c ft_utoa.c ft_itoa.c ft_printf.c ft_printf_utils.c ft_hex.c ft_free.c ft_strcmp.c ft_array_dup.c \
ft_free_split.c ft_isspace.c ft_strreplace.c ft_convert_array.c ft_strjoin_free.c

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstdup.c

OBJ	=	$(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)
		
CC	=	gcc -g

CFLAGS	=	-Wall -Wextra -Werror

RM = rm -f

NAME	=	libft.a

all:	$(NAME)

$(NAME):	$(OBJ)
				ar rcs $(NAME) $(OBJ)

bonus:		$(OBJ) $(OBJ_BONUS)
				ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
			$(RM) $(OBJ) $(OBJ_BONUS)

fclean:	clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus
