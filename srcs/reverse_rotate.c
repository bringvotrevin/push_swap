/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:12:33 by dim               #+#    #+#             */
/*   Updated: 2021/06/03 03:13:09 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_lst *tail_lst)
{
	tail_lst->tail = tail_lst->tail->prev;
}

void	rra(t_lst *tail_a)
{
	ft_rev_rotate(tail_a);
	write(1, "rra\n", 4);
}

void	rrb(t_lst *tail_b)
{
	ft_rev_rotate(tail_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_lst *tail_a, t_lst *tail_b)
{
	ft_rev_rotate(tail_a);
	ft_rev_rotate(tail_b);
	write(1, "rrr\n", 4);
}
