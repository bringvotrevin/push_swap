/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:41:09 by dim               #+#    #+#             */
/*   Updated: 2021/06/07 15:16:18 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	ft_lstnew_t(void)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (lst == NULL)
		return (NULL);
	lst->size = 0;
	lst->tail = NULL;
	return (lst);
}

t_st	ft_lstnew_s(int number)
{
	t_st	*lst;

	lst = (t_st *)malloc(sizeof(t_st));
	if (lst == NULL)
		return (NULL);
	lst->num = number;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void	ft_lstadd_tail(t_lst *tail_lst, t_lst *new)
{
	if (tail_lst == NULL || new == NULL)
		rt_error(//?);
	if (tail_lst->tail == NULL)
	{
		tail->lst->tail = new;
		tail->lst->tail->next = new;
		tail->lst->tail->prev = new;
	}
	else
	{
		new->prev = tail_lst->tail;
		new->next = tail_lst->tail->next;
		tail_lst->tail->next->prev = new;
		tail_lst->tail->next = new;
		tail_lst->tail = new;
	}
	tail_lst->size++;
}
