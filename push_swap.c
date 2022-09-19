/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:16:04 by numussan          #+#    #+#             */
/*   Updated: 2022/09/19 22:26:35 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_list(int nbr)
{
	ft_printf("%d\n", nbr);
}

void	ft_error(char *s)
{
	ft_printf("%s", s);
	exit (1);
}

void	check_is_nbrs(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			ft_error("Non numeric character\n");
		i++;
	}
}

void	add_nbr_to_list(char *s)
{
	int nbr;

	check_is_nbrs(s);
	nbr = ft_atoi(s);
	push_to_list(nbr);
}

void	ft_parsing(char	*s)
{
	int i;
	char **several_nbrs;

	i = 0;
	if (strchr(s, ' '))
	{
		several_nbrs = ft_split(s, ' ');
		while (several_nbrs[i])
		{
			add_nbr_to_list(several_nbrs[i]);
			i++;
		}			
	}
	else
		add_nbr_to_list(s);
}

int	main(int argc, char **argv)
{
	// t_stack	*a;
	// t_stack	*cursor;
	int	i;

	i = 1;
	// a = malloc(size_t(t_stack *a));
	
	while(i < argc)
	{
		ft_parsing(argv[i]);
		i++;
	}
	return (0);
}
