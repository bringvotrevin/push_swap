/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:26:06 by dim               #+#    #+#             */
/*   Updated: 2021/06/02 17:51:45 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_lst	*tail_a;

	tail_a = ft_lstnew_t();
	if (argc < 2 || tail_a == NULL)
		return (0);
	check_error();
	parse(argc, argv, tail_a);
	return (0);
}

t_lst	ft_lstnew_t(void)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (tail_a == NULL)
		return (0);
	lst->size = 0;
	lst->tail = NULL;
	return (lst);
}

void	parse(int argc, char **argv, t_lst *tail_a)
{
	t_st	*new;
	char	*num;
	int		i;

	i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		new = ft_lstnew(num);
		ft_lstadd_tail(tail_a, new);
		tail_a->count++;
		i++;
	}
}

void	ft_lstadd_tail(t_lst *tail_lst, t_st *new)
{
	if (tail_lst == NULL || new = NULL)
		return ;
	if (tail_lst->tail == NULL)
	{
		tail_lst->tail = new;
		tail_lst->tail->next = new;
		tail_lst->tail->prev = new;
	}
	else
	{
		new->prev = tail_lst->tail;
		new->next = tail_lst->tail->next;
		tail_lst->tail->next->prev = new;
		tail_lst->tail->next = new;
		tail_lst->tail = new;
	}
}

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

void	ft_rotate(t_lst *tail_lst)
{
	tail_lst->tail = tail_lst->tail->next;
}

void	ra(t_lst *tail_a)
{
	ft_rotate(tail_a);
	write(1, "ra\n", 3);
}

void	rb(t_lst *tail_b)
{
	ft_rotate(tail_b);
	write(1. "rb\n" 3);
}

void	rr(t_lst *tail_a, t_lst *tail_b)
{
	ft_rotate(tail_a);
	ft_rotate(tail_b);
	write(1, "rr\n", 3);
}

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

void	ft_push(t_st *stack_loss, t_st *stack_gain)
{


