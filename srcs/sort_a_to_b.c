/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:10:59 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 12:04:09 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		a_to_b(t_lst *tail_a, t_lst *tail_b, int *arr, int size)
{
	t_pivot	pivot;

	if (size <= 3)
		three_a_to_b(tail_a, tail_b, size);
	else
	{
		set_pivot(arr, &pivot, size);
		ft_a_to_b(tail_a, tail_b, &pivot, size);
	}
}

void		ft_a_to_b(t_lst *tail_a, t_lst *tail_b, t_pivot *pivot, int size)
{
	t_st	*cur;
	t_save	save;

	init_lstsave(&save);
	cur = tail_a->tail->next;
	while (size--)
	{
		if (cur->num >= *(pivot->p3) && cur_next(&cur))
			n_ra(tail_a, &save);
		else if (cur->num < *(pivot->p2) && cur_next(&cur))
			n_pb(tail_a, tail_b, &save);
		else if (cur_next(&cur))
		{
			n_pb(tail_a, tail_b, &save);
			n_rb(tail_b, &save);
		}
	}
	rr_stack(tail_a, tail_b, &save);
	a_to_b(tail_a, tail_b, pivot->p3, save.n_ra);
	b_to_a(tail_a, tail_b, pivot->p2, save.n_rb);
	b_to_a(tail_a, tail_b, pivot->p1, save.n_pb - save.n_rb);
}

void		three_a_to_b(t_lst *tail_a, t_lst *tail_b, int size)
{
	t_st	*max;
	t_st	*cur;

	if (size == 1)
		return ;
	max = check_max(tail_a, size);
	cur = tail_a->tail->next;
	if ((cur == max || cur->next->next == max) \
	&& check_ascending(tail_a, size))
		sa(tail_a);
	if (check_ascending(tail_a, size))
	{
		pb(tail_a, tail_b);
		sa(tail_a);
		pa(tail_a, tail_b);
	}
	if (check_ascending(tail_a, size))
		sa(tail_a);
}
