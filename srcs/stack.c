/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:49:28 by dim               #+#    #+#             */
/*   Updated: 2021/06/23 04:22:44 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_lst *tail_a, t_lst *tail_b, int *arr)
{	
	int		size;
	int		pivot[3];
	t_st	*cur;
	t_save	save;

	size = tail_a->size;
	cur = tail_a->tail->next;
	init_lstsave(&save);
	set_pivot(arr, pivot, size);
	while(size--)
	{
		if (cur->num >= pivot[1])
			n_ra(tail_a, &save);
		else if (cur->num < pivot[0])
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
		a_to_b(tail_a, tail_b, save.n_ra, pivot[2]);

}

void	a_to_b_2(t_lst *tail_a, t_lst *tail_b, int *arr, )
void	a_to_b(t_lst *tail_a, t_lst *tail_b, int size, int from)
{
	int		pivot[3];
	t_lst	*cur;
	t_save	save;

	set_pivot_2()
	init_lstinfo(&save);
	cur = tail_a->tail->next;
	while(size--)
	{
		if (cur->num >= pivot[1])
			n_ra(tail_a, &save);
		else if (cur->num < pivot[0])
		{
			n_pb(tail_b, &save);
			n_rb(tail_b, &save);
		}
		else 
			n_pb(tail_b, &save);
		cur = cur->next;
	}
	rr_stack(tail_a, tail_b, save);

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

void	b_to_a(t_lst *tail_a, t_lst *tail_b, t_save *prev_save)
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
			n_pa(tail_a, &save);
		else if (cur->num < pivot[0])
			n_rb(tail_b, &save);
		else 
		{
			n_pa(tail_a, &save);
			n_ra(tail_a, &save);
		}
		cur = cur->next;
	}
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
