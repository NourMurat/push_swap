# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 19:05:58 by numussan          #+#    #+#              #
#    Updated: 2022/10/29 23:39:08 by numussan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

SRCS 		= push_swap.c parsing.c ra_rb_rr.c sa_sb_ss_pa_pb.c operations.c sort.c

OBJS		= $(SRCS:.c=.o)

CCF			= gcc -Wall -Wextra -Werror -fsanitize=address -g

MAKELIBFT	= cd libft && make
MAKEPRINTF	= cd ft_printf && make

LIBFT		= libft/libft.a
PRINTF		= ft_printf/libftprintf.a

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKELIBFT)
	@$(MAKEPRINTF)
	@$(CCF) -o $(NAME) $(SRCS) $(LIBFT) $(PRINTF)

%.o : %.c so_long.h
	@$(CCF) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKELIBFT) clean
	@$(MAKEPRINTF) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKELIBFT) fclean
	@$(MAKEPRINTF) fclean

re: fclean all

.PHONY: all clean fclean re libft ft_printf