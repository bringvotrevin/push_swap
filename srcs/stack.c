/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:49:28 by dim               #+#    #+#             */
/*   Updated: 2021/06/22 04:36:39 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_lst *tail_a, t_lst *tail_b, int *arr)
{
	int		pivot[3];

	if (tail_a == NULL)
		return ;
	pivot[0] = arr[0];
	if (tail_b == NULL)
		return ;
	
}