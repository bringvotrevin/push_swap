/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:49:28 by dim               #+#    #+#             */
/*   Updated: 2021/06/23 22:12:19 by dim              ###   ########.fr       */
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
			n_pb(tail_b, &save);
			n_rb(tail_b, &save);
		}
		else 
			n_pb(tail_b, &save);
		cur = cur->next;
	}
	if (save.n_ra <= 3)
	{
		three_input(tail_a);
		b_to_a(tail_a, tail_b, save.n_pb - save.n_rb);
		b_to_a(tail_a, tail_b, save.n_rb);
	}
	else
		a_to_b(tail_a, tail_b, pivot.p3, save.n_ra);
}

void	a_to_b(t_lst *tail_a, t_lst *tail_b, int *arr, int size)
{
	t_pivot		pivot;

	if (size <= 3)
		three_a_to_b();
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

	init_lstinfo(&save);
	cur = tail_a->tail->next;
	while(size--)
	{
		if (cur->num >= *(pivot->p3))
			n_ra(tail_a, &save);
		else if (cur->num < *(pivot->p1))
		{
			n_pb(tail_b, &save);
			n_rb(tail_b, &save);
		}
		else 
			n_pb(tail_b, &save);
		cur = cur->next;
	}
	rr_stack(tail_a, tail_b, &save);
	a_to_b(tail_a, tail_b, pivot->p3, save.n_ra);
	b_to_a()
}

void	rr_stack(t_lst *tail_a, t_lst *tail_b, t_save *prev_save)
{
	int		diff;
	t_save	save;

	diff = prev_save->_ra - prev_save->_rb;
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

	if (size <= 3)
		three_b_to_a();
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

	init_lstinfo(&save);
	cur = tail_b->tail->next;
	while(size--)
	{
		if (cur->num >= *(pivot->p3))
			n_pa(tail_a, &save);
		else if (cur->num < *(pivot->p1))
			n_rb(tail_b, &save);
		else 
		{
			n_pa(tail_a, &save);
			n_ra(tail_a, &save);
		}
		cur = cur->next;
	}
	a_to_b(tail_a, tail_b, pivot->p3, save.n_pa);
	rra_to_b(tail_a, tail_b, pivot->p2, &save);

}

void	rra_to_b(t_lst *tail_a, t_lst *tail_b, t_save *prev_save)
{
	int		*arr;
	t_save	save;

	arr = arr_forsort();
	if (arr == NULL)
		return ; //error????????????????
	init_lstinfo(&save);
	while()
	{
		if (cur->num >= pivot[1])
			n_rra(tail_a, &save);
		else if (cur->num < pivot[0])
		{
			n_rra(tail_a, &save);
			n_pb(tail_b, &save);
			n_rb(tail_b, &save);
		}
		else 
		{
			n_rra(tail_a, &save);
			n_pb(tail_b, &save);
		}
		cur = cur->next;
	}
	rr_stack();
}

void	three_a_to_b()
{

}

void	three_b_to_a()
{

}