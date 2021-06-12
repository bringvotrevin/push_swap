/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:21:55 by dim               #+#    #+#             */
/*   Updated: 2021/06/12 22:22:43 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_util.h"
#include "lst.h"
#include "util.h"

t_st	*check_min(t_lst *tail_a)
{
	t_st	*minlst;
	t_st	*cur;
	int		size;

	minlst = tail_a->tail->next;
	cur = tail_a->tail->next;
	size = tail_a->size;
	while (size-- > 1)
	{
		if (cur->num < cur->next->num)
			minlst = cur;
		cur = cur->next;
	}
	return (minlst);
}

t_st	*check_max(t_lst *tail_a)
{
	t_st	*maxlst;
	t_st	*cur;
	int		size;

	maxlst = tail_a->tail->next;
	cur = tail_a->tail->next;
	size = tail_a->size;
	while (size-- > 1)
	{
		if (cur->num < cur->next->num)
			maxlst = cur;
		cur = cur->next;
	}
	return (maxlst);
}

void	check_ascending(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*cur;
	int		size;

	cur = tail_a->tail->next;
	size = tail_a->size - 1;
	while (size-- > 0)
	{
		if (cur->num < cur->next->num)
			three_input(tail_a, tail_b);
		cur = cur->next;
	}
}

void	three_input(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*min;
	t_st	*max;
	
	min = check_min(tail_a);
	max = check_max(tail_a);
	check_
	if (min->next == max)
	{
		ra(tail_a);
		check_ascending(tail_a, tail_b);
	}
	else
	{
		sa(tail_a);
		check_ascending(tail_a, tail_b);
	}
}

void	count_input(t_lst *tail_a, t_lst *tail_b)
{
	if (tail_a->size <= 3)
		three_input(tail_a, tail_b);
	/* else if (tail_a->size )
		five_input(tail_a, tail_b);
	else if (tail_a->size )
		hundred_input(tial_a, tail_b);
	else if (tail_a->size >= 500)
		fivehundred_input(tail_a, tail_b); */
	
}

int		push_swap(t_lst *tail_a)
{
	t_lst	*tail_b;

	tail_b = ft_lstnew_t();
	if (tail_b == NULL)
		return (0);
	count_input(tail_a, tail_b);
	return (1);
}
