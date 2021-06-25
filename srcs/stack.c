/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:49:28 by dim               #+#    #+#             */
/*   Updated: 2021/06/26 02:29:34 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printtail(t_lst *tail_a)
{
	t_st	*cur;
	int		size;

	size = tail_a->size;
	cur = tail_a->tail->next;
	while (size--)
	{
		printf("lst->num : %lld\n", cur->num);
		cur = cur->next;
	}
}

void	sort_stack(t_lst *tail_a, t_lst *tail_b, int *arr)
{	// 처음 3분할
	int			size;
	t_st		*cur;
	t_save		save;
	t_pivot		pivot;

	init_lstsave(&save);
	set_pivot(arr, &pivot, tail_a->size);
	printf("%d, %d, %d\n", *pivot.p1, *pivot.p2, *pivot.p3);
	size = tail_a->size;
	cur = tail_a->tail->next;
	while(size--)
	{
		if (cur->num >= *(pivot.p3))
		{
			cur = cur->next;
			n_ra(tail_a, &save);
		}
		else if (cur->num < *(pivot.p2))
		{
			cur = cur->next;
			n_pb(tail_a, tail_b, &save);
			n_rb(tail_b, &save);
		}
		else
		{
			cur = cur->next;
			n_pb(tail_a, tail_b, &save);
		}
	}
	printf("n.ra: %d\n", save.n_ra);
	if (save.n_ra <= 3)
	{
		printf("!");
		three_input(tail_a);
		b_to_a(tail_a, tail_b, pivot.p2, save.n_pb - save.n_rb);
		b_to_a(tail_a, tail_b, pivot.p1, save.n_rb);
	}
	else
	{
		a_to_b(tail_a, tail_b, pivot.p3, save.n_ra);
		b_to_a(tail_a, tail_b, pivot.p2, save.n_pb - save.n_rb);
		b_to_a(tail_a, tail_b, pivot.p1, save.n_rb);
	}
}

void	a_to_b(t_lst *tail_a, t_lst *tail_b, int *arr, int size)
{
	t_pivot		pivot;

	if (size <= 3)
		three_a_to_b(tail_a, tail_b, size);
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
		{
			cur = cur->next;
			n_ra(tail_a, &save);
		}
		else if (cur->num < *(pivot->p2))
		{
			cur = cur->next;
			n_pb(tail_a, tail_b, &save);
		}
		else
		{
			cur = cur->next;
			n_pb(tail_a, tail_b, &save);
			n_rb(tail_b, &save);
		}
	}
	// printf("==========\n");
	// printf("%d %d %d\n", save.n_ra, save.n_rb, save.n_pb);
	rr_stack(tail_a, tail_b, &save);
	a_to_b(tail_a, tail_b, pivot->p3, save.n_ra);
	// printf("%d %d %d\n", save.n_ra, save.n_rb, save.n_pb);
	// while(1);
	b_to_a(tail_a, tail_b, pivot->p2, save.n_rb);
	b_to_a(tail_a, tail_b, pivot->p1, save.n_pb - save.n_rb);
}

void	rr_stack(t_lst *tail_a, t_lst *tail_b, t_save *prev_save)
{
	int		diff;
	t_save	save;

	save.n_ra = prev_save->n_ra;
	save.n_rb = prev_save->n_rb;
	diff = prev_save->n_ra - prev_save->n_rb;
	if (diff >= 0)
	{
		while (save.n_rb--)
			n_rrr(tail_a, tail_b, &save);
		while (diff--)
			n_ra(tail_a, &save);
	}
	else
	{
		while (save.n_ra--)
			n_rrr(tail_a, tail_b, &save);
		while (diff++)
			n_rb(tail_b, &save);
	}
}

void	b_to_a(t_lst *tail_a, t_lst *tail_b, int *arr, int size)
{
	t_pivot		pivot;

	printf("before two btoa size: %d\n" , size);
	if (size <= 2)
	{
		two_b_to_a(tail_a, tail_b, size);
		return ;
	}
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
	printtail(tail_b);
	while(size--)
	{
		if (cur->num >= *(pivot->p3))
		{
			cur = cur->next;
			n_pa(tail_a, tail_b, &save);
		}
		else if (cur->num < *(pivot->p2))
		{
			cur = cur->next;
			n_rb(tail_b, &save);
		}
		else 
		{
			cur = cur->next;
			n_pa(tail_a, tail_b, &save);
			n_ra(tail_a, &save);
		}
	}
	a_to_b(tail_a, tail_b, pivot->p3, save.n_pa - save.n_ra);
	// rra_to_b(tail_a, tail_b, pivot->p2, &save);
	rr_stack(tail_a, tail_b, &save);
	a_to_b(tail_a, tail_b, pivot->p2, save.n_ra);
	b_to_a(tail_a, tail_b, pivot->p1, save.n_rb);
}

/* void	rra_to_b(t_lst *tail_a, t_lst *tail_b, int *arr, t_save *prev_save)
{
	int			i;
	t_pivot		pivot;

	i = prev_save->n_rb;
	while (i--)
		rrb(tail_b);
	if (prev_save->n_ra <= 2)
		two_rra_to_b(tail_a, prev_save->n_ra);
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
	int		tmp;

	init_lstsave(&save);
	cur = tail_a->tail;
	while (size--)
	{
		if (cur->num >= *(pivot->p3))
		{
			cur = cur->prev;
			n_rra(tail_a, &save);
		}
		else if (cur->num < *(pivot->p2))
		{
			cur = cur->prev;
			n_rra(tail_a, &save);
			n_pb(tail_a, tail_b, &save);
		}
		else 
		{
			cur = cur->prev;
			n_rra(tail_a, &save);
			n_pb(tail_a, tail_b, &save);
			n_rb(tail_b, &save);
		}
	}
	tmp = save.n_rb;
	while (tmp--)
		n_rrb(tail_b, &save);
	a_to_b(tail_a, tail_b, pivot->p3, save.n_rra - save.n_pb);
	b_to_a(tail_a, tail_b, pivot->p2, save.n_rrb);
	b_to_a(tail_a, tail_b, pivot->p1, save.n_pb - save.n_rb);
}
 */

void	three_a_to_b(t_lst *tail_a, t_lst *tail_b, int size)
{
	t_st	*min;
	t_st	*max;
	t_st	*cur;

	if (check_ascending(tail_a, size) == 1)
		return ;
	min = check_min(tail_a, size);
	max = check_max(tail_a, size);
	cur = tail_a->tail->next;
	if (cur == max || cur->next->next == max)
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

void	two_b_to_a(t_lst *tail_a, t_lst *tail_b, int size)
{
	pa(tail_a, tail_b);
	if (size == 2)
		pa(tail_a, tail_b);
	if (check_ascending(tail_a, 2) && size == 2)
		sa(tail_a);
}

void	two_rra_to_b(t_lst *tail_a, int size)
{
	rra(tail_a);
	if (size == 2)
		rra(tail_a);
	if (check_ascending(tail_a, 2) && size == 2)
		sa(tail_a);
}
