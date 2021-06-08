/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:13:29 by dim               #+#    #+#             */
/*   Updated: 2021/06/08 13:53:35 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_lst *stack_loss, t_lst *stack_gain)
{
	t_st	*head_loss;
	t_st	*head_gain;

	head_loss = stack_loss->tail->next;
	head_gain = stack_gain->tail->next;

	stack_loss->tail->next = stack_loss->tail->next->next;
	stack_loss->tail->next->prev = stack_loss->tail;
	stack_gain->tail->next = head_loss;
	head_loss->prev = stack_gain->tail;
	head_loss->next = head_gain;
	head_gain->prev = head_loss;
	stack_loss->size--;
	stack_gain->size++;
}

void	pa(t_lst *tail_a, t_lst *tail_b)
{
	ft_push(tail_b, tail_a);
	write(1, "pa\n", 3);
}

void	pb(t_lst *tail_a, t_lst *tail_b)
{
	ft_push(tail_a, tail_b);
	write(1, "pb\n", 3);
}
