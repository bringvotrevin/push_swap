/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:49:28 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 12:13:39 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_stack(t_lst *tail_a, t_lst *tail_b, int *arr)
{
	int			size;
	t_st		*cur;
	t_save		save;
	t_pivot		pivot;

	init_lstsave(&save);
	set_pivot(arr, &pivot, tail_a->size);
	size = tail_a->size;
	cur = tail_a->tail->next;
	while (size--)
	{
		if (cur->num >= *(pivot.p3) && cur_next(&cur))
			n_ra(tail_a, &save);
		else if (cur->num < *(pivot.p2) && cur_next(&cur))
		{
			n_pb(tail_a, tail_b, &save);
			n_rb(tail_b, &save);
		}
		else if (cur_next(&cur))
			n_pb(tail_a, tail_b, &save);
	}
	sort_stack_rest(tail_a, tail_b, &pivot, &save);
}

void			sort_stack_rest(t_lst *tail_a, t_lst *tail_b, \
t_pivot *pivot, t_save *save)
{
	if (save->n_ra <= 3)
	{
		three_input(tail_a);
		b_to_a(tail_a, tail_b, pivot->p2, save->n_pb - save->n_rb);
		b_to_a(tail_a, tail_b, pivot->p1, save->n_rb);
	}
	else
	{
		a_to_b(tail_a, tail_b, pivot->p3, save->n_ra);
		b_to_a(tail_a, tail_b, pivot->p2, save->n_pb - save->n_rb);
		b_to_a(tail_a, tail_b, pivot->p1, save->n_rb);
	}
}

void			rr_stack(t_lst *tail_a, t_lst *tail_b, t_save *prev_save)
{
	int			diff;
	t_save		save;

	save.n_ra = prev_save->n_ra;
	save.n_rb = prev_save->n_rb;
	diff = prev_save->n_ra - prev_save->n_rb;
	if (diff >= 0)
	{
		while (save.n_rb--)
			rrr(tail_a, tail_b);
		while (diff--)
			rra(tail_a);
	}
	else
	{
		while (save.n_ra--)
			rrr(tail_a, tail_b);
		while (diff++)
			rrb(tail_b);
	}
}

void			two_rra_to_b(t_lst *tail_a, int size)
{
	rra(tail_a);
	if (size == 2)
		rra(tail_a);
	if (check_ascending(tail_a, 2) && size == 2)
		sa(tail_a);
}
