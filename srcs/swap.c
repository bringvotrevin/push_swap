/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:10:41 by dim               #+#    #+#             */
/*   Updated: 2021/06/18 13:44:26 by dim              ###   ########.fr       */
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
	if (tail_a->size > 2)
		ft_swap(tail_a->tail);
	write(1, "sa\n", 3);
}

void	sb(t_lst *tail_b)
{
	if (tail_b->size > 2)
		ft_swap(tail_b->tail);
	write(1, "sb\n", 3);
}

void	ss(t_lst *tail_a, t_lst *tail_b)
{
	if (tail_a->size > 2)
		ft_swap(tail_a->tail);
	if (tail_b->size > 2)
		ft_swap(tail_b->tail);
	write(1, "ss\n", 3);
}
