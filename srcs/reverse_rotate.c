/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:12:33 by dim               #+#    #+#             */
/*   Updated: 2021/06/22 04:14:43 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	st_rev_rotate(t_lst *tail_lst)
{
	tail_lst->tail = tail_lst->tail->prev;
}

void	rra(t_lst *tail_a)
{
	if (tail_a->size > 1)
		st_rev_rotate(tail_a);
	write(1, "rra\n", 4);
}

void	rrb(t_lst *tail_b)
{
	if (tail_b->size > 1)
		st_rev_rotate(tail_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_lst *tail_a, t_lst *tail_b)
{
	if (tail_a->size > 1)
		st_rev_rotate(tail_a);
	if (tail_b->size > 1)
		st_rev_rotate(tail_b);
	write(1, "rrr\n", 4);
}
