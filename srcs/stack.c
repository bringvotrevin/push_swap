/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:49:28 by dim               #+#    #+#             */
/*   Updated: 2021/06/25 15:25:53 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_lst *tail_a, t_lst *tail_b, int *arr)
{	// 처음 3분할
	int			size;
	t_st		*cur;
	t_save		save;
	t_pivot		pivot;

	init_lstsave(&save);
	set_pivot(arr, &pivot, tail_a->size);
	size = tail_a->size;
	cur = tail_a->tail->next;
	while(size--)
	{
		if (cur->num >= *(pivot.p3))
			n_ra(tail_a, &save);
		else if (cur->num < *(pivot.p2))
		{
			n_pb(tail_a, tail_b, &save);
			n_rb(tail_b, &save);
		}
		else 
			n_pb(tail_a, tail_b, &save);
		cur = cur->next;
	}
	if (save.n_ra <= 3)
	{
		three_input(tail_a);
		b_to_a(tail_a, tail_b, pivot.p2, save.n_pb - save.n_rb);
		b_to_a(tail_a, tail_b, pivot.p1, save.n_rb);
	}
	else
		a_to_b(tail_a, tail_b, pivot.p3, save.n_ra);
}

void	a_to_b(t_lst *tail_a, t_lst *tail_b, int *arr, int size)
{
	t_pivot		pivot;

	if (size <= 3)
		three_a_to_b(tail_a, tail_b);
	else
	{
		set_pivot(arr, &pivot, size);
		ft_a_to_b(tail_a, tail_b, &pivot, size);
	}
}

void	ft_a_to_b(t_lst *tail_a, t_lst *tail_b, t_pivot *pivot, int size)
{
	t_st		*cur;
	t_save		save;

	init_lstsave(&save);
	cur = tail_a->tail->next;
	while(size--)
	{
		if (cur->num >= *(pivot->p3))
			n_ra(tail_a, &save);
		else if (cur->num < *(pivot->p2))
		{
			n_pb(tail_a, tail_b, &save);
			n_rb(tail_b, &save);
		}
		else 
			n_pb(tail_a, tail_b, &save);
		cur = cur->next;
	}
	rr_stack(tail_a, tail_b, &save);
	a_to_b(tail_a, tail_b, pivot->p3, save.n_ra);
	b_to_a(tail_a, tail_b, pivot->p2, save.n_pb - save.n_rb);
	b_to_a(tail_a, tail_b, pivot->p1, save.n_rb);
}

void	rr_stack(t_lst *tail_a, t_lst *tail_b, t_save *prev_save)
{
	int		diff;
	t_save	save;

	diff = prev_save->n_ra - prev_save->n_rb;
	if (diff >= 0)
	{
		while (prev_save->n_rb--)
			n_rrr(tail_a, tail_b, &save);
		while (diff--)
			n_ra(tail_a, &save);
	}
	else
	{
		while (prev_save->n_ra--)
			n_rrr(tail_a, tail_b, &save);
		while (diff++)
			n_rb(tail_b, &save);
	}
}

void	b_to_a(t_lst *tail_a, t_lst *tail_b, int *arr, int size)
{
	t_pivot		pivot;

	if (size <= 2)
		two_b_to_a(tail_a, tail_b);
	else
	{
		set_pivot(arr, &pivot, size);
		ft_b_to_a(tail_a, tail_b, &pivot, size);
	}
}

void	ft_b_to_a(t_lst *tail_a, t_lst *tail_b, t_pivot *pivot, int size)
{
	t_st	*cur;
	t_save	save;

	init_lstsave(&save);
	cur = tail_b->tail->next;
	while(size--)
	{
		if (cur->num >= *(pivot->p3))
			n_pa(tail_a, tail_b, &save);
		else if (cur->num < *(pivot->p2))
			n_rb(tail_b, &save);
		else 
		{
			n_pa(tail_a, tail_b, &save);
			n_ra(tail_a, &save);
		}
		cur = cur->next;
	}
	a_to_b(tail_a, tail_b, pivot->p3, save.n_pa);
	rra_to_b(tail_a, tail_b, pivot->p2, &save);
	b_to_a(tail_a, tail_b, pivot->p1, save.n_rb);
}

void	rra_to_b(t_lst *tail_a, t_lst *tail_b, int *arr, t_save *prev_save)
{
	int			i;
	t_pivot		pivot;

	i = prev_save->n_rb;
	while (i--)
		rrb(tail_b);
	if (prev_save->n_ra <= 2)
		two_rra_to_b(tail_a);
	else
	{
		set_pivot(arr, &pivot, prev_save->n_ra);
		ft_rra_to_b(tail_a, tail_b, &pivot, prev_save->n_ra);

	}
}

void	ft_rra_to_b(t_lst *tail_a, t_lst *tail_b, t_pivot *pivot, int size)
{
	t_st	*cur;
	t_save	save;

	init_lstsave(&save);
	cur = tail_a->tail;
	while (size--)
	{
		if (cur->num >= *(pivot->p3))
			n_rra(tail_a, &save);
		else if (cur->num < *(pivot->p2))
		{
			n_rra(tail_a, &save);
			n_pb(tail_a, tail_b, &save);
		}
		else 
		{
			n_rra(tail_a, &save);
			n_pb(tail_a, tail_b, &save);
			n_rb(tail_b, &save);
		}
		cur = cur->prev;
	}
	while (save.n_rb--)
		n_rrb(tail_b, &save);
	a_to_b(tail_b, tail_b, pivot->p3, save.n_rra);
	b_to_a(tail_a, tail_b, pivot->p2, save.n_pb - save.n_rrb);
	b_to_a(tail_a, tail_b, pivot->p1, save.n_rrb);
}

void	three_a_to_b(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*min;
	t_st	*max;
	t_st	*cur;

	min = check_min(tail_a, 3);
	max = check_max(tail_a, 3);
	cur = tail_a->tail->next;
	if (check_ascending(tail_a, 3) == 1)
		return ;
	if (cur == max || cur->next->next == max)
		sa(tail_a);
	if (check_ascending(tail_a, 3))
	{
		pb(tail_a, tail_b);
		sa(tail_a);
		pa(tail_a, tail_b);
	}
	if (check_ascending(tail_a, 3))
		sa(tail_a);
}

void	two_b_to_a(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*cur;

	pa(tail_a, tail_b);
	pa(tail_a, tail_b);
	cur = tail_a->tail->next;
	if (check_ascending(tail_a, 2))
		sa(tail_a);
}

void	two_rra_to_b(t_lst *tail_a)
{
	rra(tail_a);
	rra(tail_a);
	if (check_ascending(tail_a, 2))
		sa(tail_a);
}