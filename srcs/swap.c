/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:10:41 by dim               #+#    #+#             */
/*   Updated: 2021/06/03 03:11:30 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_st *stack)
{
	int		temp;

	temp = stack->next->num;
	stack->next->num = stack->next->next->num;
	stack->next->next->num = temp;
}

void	sa(t_lst *tail_a)
{
	ft_swap(tail_a->tail);
	write(1, "sa\n", 3);
}

void	sb(t_lst *tail_b)
{
	ft_swap(tail_b->tail);
	write(1, "sb\n", 3);
}

void	ss(t_lst *tail_a, t_lst *tail_b)
{
	ft_swap(tail_a->tail);
	ft_swap(tail_b->tail);
	write(1, "ss\n", 3);
}
