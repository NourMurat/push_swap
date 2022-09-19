/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:17:20 by numussan          #+#    #+#             */
/*   Updated: 2022/09/19 21:36:39 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
    int num;
    struct s_stack *next;
}   t_stack;



void    ft_parsing(char	*argv);
void	add_nbr_to_list(char *s);
void	check_is_nbrs(char *s);
void	push_to_list(int nbr);
void	ft_error(char *s);

#endif
