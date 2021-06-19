/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ids <ids@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 03:13:29 by dim               #+#    #+#             */
/*   Updated: 2021/06/20 03:18:25 by ids              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_st_gain(t_lst *stack_gain, t_st *head_loss)
{
	t_st	*head_gain;
	
	if (stack_gain->size != 0)
		head_gain = stack_gain->tail->next;
	if (stack_gain->size == 0)
	{
		stack_gain->tail = head_loss;
		stack_gain->tail->next = head_loss;
	}
	else
	{
		stack_gain->tail->next = head_loss;
		head_loss->next = head_gain;
		head_gain->prev = head_loss;
	}
	head_loss->prev = stack_gain->tail;
}

void	st_push(t_lst *stack_loss, t_lst *stack_gain)
{
	t_st	*head_loss;

	head_loss = stack_loss->tail->next;
	if (stack_loss->size > 1)
	{
		stack_loss->tail->next = stack_loss->tail->next->next;
		stack_loss->tail->next->prev = stack_loss->tail;
	}
	else
		stack_loss->tail = NULL;
	push_st_gain(stack_gain, head_loss);
	stack_loss->size--;
	stack_gain->size++;
}

void	pa(t_lst *tail_a, t_lst *tail_b)
{
	if (tail_b > 0)
		st_push(tail_b, tail_a);
	write(1, "pa\n", 3);
}

void	pb(t_lst *tail_a, t_lst *tail_b)
{
	if (tail_a > 0)
		st_push(tail_a, tail_b);
	write(1, "pb\n", 3);
}
