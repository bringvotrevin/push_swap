/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:37:29 by dim               #+#    #+#             */
/*   Updated: 2021/06/10 20:52:44 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	memfree(char **arr, t_lst *tail_lst)
{
	if (arr)
		free_arr(arr);
	if (tail_lst)
		free_lst(tail_lst);
}

void	free_arr(char **arr)
{
	int		i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_lst(t_lst *tail_lst)
{
	t_st	*cur;
	t_st	*cur2;
	int		size;

	if (tail_lst == NULL)
		return ;
	size = tail_lst->size;
	cur = tail_lst->tail;
	while (size--)
	{
		if (tail_lst->size != 0)
		{
			cur2 = cur->next;
			free(cur);
			cur = cur2;
		}
		else
		{
			free(cur);
			cur = NULL;
			break;
		}
	}
	free(tail_lst);
	tail_lst = NULL;
}
