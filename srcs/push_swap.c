/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:21:55 by dim               #+#    #+#             */
/*   Updated: 2021/06/29 15:12:49 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		three_input(t_lst *tail_lst)
{
	t_st	*min;
	t_st	*max;

	min = check_min(tail_lst, 3);
	max = check_max(tail_lst, 3);
	if (min->next == max && check_ascending(tail_lst, 3))
		sa(tail_lst);
	if (min == tail_lst->tail && check_ascending(tail_lst, 3))
		rra(tail_lst);
	if (check_ascending(tail_lst, 3))
		ra(tail_lst);
}

void		five_input(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*min;
	t_st	*max;
	t_st	*cur;
	int		size;
	int		flag;

	size = tail_a->size;
	flag = 0;
	cur = tail_a->tail->next;
	min = check_min(tail_a, 5);
	max = check_max(tail_a, 5);
	while (size--)
	{
		if ((cur == min || cur == max))
		{
			cur = cur->next;
			pb(tail_a, tail_b);
			flag++;
			if (flag == 2)
				break ;
		}
		else if (cur_next(&cur))
			ra(tail_a);
	}
	five_input2(tail_a, tail_b, max, flag);
}

void		five_input2(t_lst *tail_a, t_lst *tail_b, t_st *max, int flag)
{
	three_input(tail_a);
	while (flag--)
	{
		pa(tail_a, tail_b);
		if (tail_a->tail->next == max)
			ra(tail_a);
	}
}

void		more_than_five(t_lst *tail_a, t_lst *tail_b)
{
	int		*arr;

	arr = arr_forsort(tail_a);
	quick_sort(0, tail_a->size - 1, arr);
	sort_stack(tail_a, tail_b, arr);
	free(arr);
}

void		push_swap(t_lst *tail_a)
{
	t_lst	*tail_b;

	tail_b = ft_lstnew_t();
	if (check_ascending(tail_a, tail_a->size) == 0)
		exit(0);
	if (tail_a->size <= 3)
		three_input(tail_a);
	else if (tail_a->size > 3 && tail_a->size <= 5)
		five_input(tail_a, tail_b);
	else if (tail_a->size > 5)
		more_than_five(tail_a, tail_b);
	free_lst(tail_b);
}
