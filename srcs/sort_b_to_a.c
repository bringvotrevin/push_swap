/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:12:24 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 12:06:36 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		b_to_a(t_lst *tail_a, t_lst *tail_b, int *arr, int size)
{
	t_pivot	pivot;

	if (size <= 2)
		two_b_to_a(tail_a, tail_b, size);
	else
	{
		set_pivot(arr, &pivot, size);
		ft_b_to_a(tail_a, tail_b, &pivot, size);
	}
}

void		ft_b_to_a(t_lst *tail_a, t_lst *tail_b, t_pivot *pivot, int size)
{
	t_st	*cur;
	t_save	save;

	init_lstsave(&save);
	cur = tail_b->tail->next;
	while (size--)
	{
		if (cur->num >= *(pivot->p3) && cur_next(&cur))
			n_pa(tail_a, tail_b, &save);
		else if (cur->num < *(pivot->p2) && cur_next(&cur))
			n_rb(tail_b, &save);
		else if (cur_next(&cur))
		{
			n_pa(tail_a, tail_b, &save);
			n_ra(tail_a, &save);
		}
	}
	a_to_b(tail_a, tail_b, pivot->p3, save.n_pa - save.n_ra);
	rr_stack(tail_a, tail_b, &save);
	a_to_b(tail_a, tail_b, pivot->p2, save.n_ra);
	b_to_a(tail_a, tail_b, pivot->p1, save.n_rb);
}

void		two_b_to_a(t_lst *tail_a, t_lst *tail_b, int size)
{
	pa(tail_a, tail_b);
	if (size == 2)
		pa(tail_a, tail_b);
	if (check_ascending(tail_a, 2) && size == 2)
		sa(tail_a);
}
