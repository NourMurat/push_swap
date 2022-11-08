/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:17:20 by numussan          #+#    #+#             */
/*   Updated: 2022/11/08 10:25:33 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct  s_stack
{
	int 			nbr;
	int				pos;
	int				rotA;
	int				revrotA;
	int				rotB;
	int				revrotB;
	int				best;
	struct s_stack	*next;
}	t_stack;

void	ft_error(char *s);
void	ft_free_stack(t_stack **head);
void	ft_free_after_split(char **s);
void	ft_err_free_split_and_list(t_stack **head, char **str, char *s);

void	ft_parsing_and_fill_list_a(int argc, char **s, t_stack **a);
char	**ft_separate_string(int argc, char **s);
void	ft_check_spaces(char **s);
void	ft_check_dublication(char **s);
void	ft_is_it_number(t_stack **a, char **str, char *s);
void	ft_add_numbers_to_stack_a(t_stack **a, char **str, char *s);

void	ft_print_stack(t_stack **head); // remove it before submit
void	ft_check_dubl(t_stack **a);

void	op_fill_list_a(t_stack **a, int nbr);
t_stack	*op_find_last(t_stack *head);
t_stack	*op_find_prelast(t_stack *head);
int		op_stack_size(t_stack **head);
void	op_push_to_head(t_stack **head, int nbr);
void    op_delete_head(t_stack **head);
int		op_check_sorted_or_presorted(t_stack **a);

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

void	ft_sorting(t_stack **a);
void    sorting_3(t_stack **a);
void	sorting_4(t_stack **a, t_stack **b);
void	sorting_5(t_stack **a, t_stack **b);
void	fill_pos(t_stack **a);
int		find_min_in_stack(t_stack **a, int *best_pos);
void	push_min_to_b(t_stack **a, t_stack **b, int min, int best_pos);
void	preparation_for_big_sorting(t_stack **a, t_stack **b);
void	find_min_max_med(t_stack **a, int *min, int *max, int *med);
int		*fill_array(t_stack **a, int *arr);
int		*insertion_sort_array(t_stack **a, int *arr);
void	determine_position(t_stack **head, int *arr);
void	transfer_to_stack_b(t_stack **a, t_stack **b);
void    presort_3(t_stack **a);

// void	reset_i(t_stack **a, t_stack **b);

void    transfer_to_stack_a(t_stack **a, t_stack **b);
void	count_moves_b(t_stack **b);
void	count_moves_a(t_stack **a, t_stack **b);

// void	transfer_to_stack_a(t_stack **head_a, t_stack **head_b);
// void	transfer_to_stack_a(t_stack **head_a, t_stack **head_b);
// void	scoring_in_b(t_stack *head_b);
// void	scoring_in_a(t_stack *head_a, t_stack *head_b);
// t_stack	*make_decision(t_stack *head, int *transfer_type);
// void	process_decision(t_stack **head_a, t_stack **head_b, t_stack *elem, int *ttype);



#endif
