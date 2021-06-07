/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:37:29 by dim               #+#    #+#             */
/*   Updated: 2021/06/07 17:33:49 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	memfree(char **arr, t_lst *tail_a)
{
	free(arr);
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
