/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:21:55 by dim               #+#    #+#             */
/*   Updated: 2021/06/13 19:34:04 by dim              ###   ########.fr       */
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

	cur = tail_a->tail->next;
	minlst = cur;
	size = tail_a->size;
	while (size-- > 1)
	{
		if (minlst->num > cur->next->num)
			minlst = cur->next;
		cur = cur->next;
	}
	return (minlst);
}

t_st	*check_max(t_lst *tail_a)
{
	t_st	*maxlst;
	t_st	*cur;
	int		size;

	cur = tail_a->tail->next;
	maxlst = cur;
	size = tail_a->size;
	while (size-- > 1)
	{
		if (maxlst->num < cur->next->num)
			maxlst = cur->next;
		cur = cur->next;
	}
	return (maxlst);
}

int		check_ascending(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*cur;
	int		size;

	if (tail_b)
	cur = tail_a->tail->next;
	size = tail_a->size;
/* 	if (size == 2)
	{
		
	} */
	while (size-- > 1)
	{
		if (cur->num > cur->next->num)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int		three_input(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*min;
	t_st	*max;
	// int		i;
	
	min = check_min(tail_a);
	max = check_max(tail_a);
	printf("min : %lld, max : %lld\n", min->num, max->num);
	// if (check_ascending(tail_a, tail_b) == 1)
	// 	return (1);
	if (min->next != max)
		sa(tail_a);
	if (min->next == max && check_ascending(tail_a, tail_b))
		ra(tail_a);
	if (!check_ascending(tail_a, tail_b))
		return (1);
	three_input(tail_a, tail_b);
	return (1);
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
