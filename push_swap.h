/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:17:20 by numussan          #+#    #+#             */
/*   Updated: 2022/09/23 21:22:44 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
    int nbr;
    struct s_stack *next;
}   t_stack;

char	**ft_separate_string(int argc, char **argv);
void	ft_check_dublication(int argc, char **new_argv);
void    ft_parsing(char	*argv);
void 	add_nbr_to_list(char *s);
void	ft_check_is_it_nbr(char *s);
void	push_to_list(int nbr);
void	ft_error(char *s);

#endif
