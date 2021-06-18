/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 03:26:35 by dim               #+#    #+#             */
/*   Updated: 2021/06/19 03:27:28 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_util.h"


void		five_input(t_lst *tail_a, t_lst *tail_b)
{
	/*  int		*arr;

	arr = arr_forsort(tail_a);
	if (arr == NULL)
		return (0);
	 */
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
	printf("min : %lld, max : %lld\n", min->num, max->num);
	while(size--)
	{
		if (tail_a->tail->next == min || \
		tail_a->tail->next == max)
		{
			pb(tail_a, tail_b);
			flag++;
			if (flag == 2)
				break;
		}
		else
			ra(tail_a);
	}
	three_input(tail_a, tail_b);
	while (flag--)
	{
		pa(tail_a, tail_b);
		if (tail_a->tail->next == max)
			ra(tail_a);
	}
}
