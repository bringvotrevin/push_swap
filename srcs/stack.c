/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:49:28 by dim               #+#    #+#             */
/*   Updated: 2021/06/22 19:20:58 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_lstinfo(t_save *save)
{
	save->n_pa = 0;
	save->n_pb = 0;
	save->n_ra = 0;
	save->n_rb = 0;
	save->n_rra = 0;
	save->n_rrb = 0;
}

void	sort_stack(t_lst *tail_a, t_lst *tail_b, int *arr)
{
	// a_to_b 
	/* int		pivot[2]; // make tester

	if (tail_a == NULL)
		return ;
	pivot[0] = arr[0];
	if (tail_b == NULL)
		return ; */
	
	int		pivot[2];
	int		size;
	int		i;
	t_st	*cur;
	t_save	save;

	init_lstinfo(&save);
	size = tail_a->size;
	cur = tail_a->tail->next;
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
		three_input(tail_a, tail_b);
	a_to_b();

}

void	a_to_b(t_lst *tail_a, t_lst *tail_b, t_save prev_save)
{
	t_save	save;

	init_lstinfo(&save);
	while()
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

void	set_pivot(int *arr, int *pivot, int size)
{

	pivot[0] = arr[size / 3];
	pivot[1] = arr[(size / 3) * 2];


}