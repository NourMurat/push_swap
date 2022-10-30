/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:17:20 by numussan          #+#    #+#             */
/*   Updated: 2022/10/30 05:07:46 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct  s_stack
{
	int 			nbr;
	int				size;
	struct s_stack	*next;
}   t_stack;

// typedef struct	s_number
// {
// 	int 			number;
// 	struct s_number	*next_number;
// }   t_number;

// typedef struct  s_stack
// {
// 	t_number	*head_number;
// 	t_number	*last_number;
// 	int			size_of_stack;
// 	int			stack_position;
// }   t_stack;

void	ft_error(char *s);

void	ft_parsing_and_fill_list_a(int argc, char **s, t_stack **a);
char	**ft_separate_string(int argc, char **s);
void	ft_check_dublication(char **s);
void	ft_is_it_number(char *s);
void	ft_add_numbers_to_stack_a(t_stack **a, char *s);

void	op_fill_list_a(t_stack **a, int nbr);
t_stack	*op_find_last(t_stack *head);
t_stack	*op_find_prelast(t_stack *head);
int		op_stack_size(t_stack **head);
void	op_push_to_head(t_stack **head, int nbr);
void    op_delete_head(t_stack **head);

void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **head_a, int flag);
void	rb(t_stack **head_b, int flag);
void	rr(t_stack **head_a, t_stack **head_b);
void	rra(t_stack **head_a, int flag);
void    rrb(t_stack **head_b, int flag);
void	rrr(t_stack **head_a, t_stack **head_b);

void	ft_count_stack_a_and_sort(t_stack **a);
void    sorting_2_3(t_stack **a);
int		preparation_for_big_sorting(t_stack **a);
int		*fill_arr(t_stack **a, int *arr);
int		*insertion_sort_arr(t_stack **a, int *arr);


#endif
