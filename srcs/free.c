/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:37:29 by dim               #+#    #+#             */
/*   Updated: 2021/06/08 16:30:29 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	memfree(char **arr, t_lst *tail_a)
{
	if (arr)
		free_arr(arr);
	if (tail_a)
		free_lst(tail_a);
}


void	free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}


void	free_lst(t_lst *tail_lst)
{
	t_st	cur;
	t_st	cur2;

	cur = tail_lst->tail;
	while (tail_lst->size--)
	{
		cur2 = cur->next;
		free(cur);
		cur = cur2;
	}
	free(tail_lst);
	tail_lst = NULL;
}
