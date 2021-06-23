/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:24:18 by dim               #+#    #+#             */
/*   Updated: 2021/06/23 02:38:33 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_st	*check_min(t_lst *tail_a, int size)
{
	t_st	*minlst;
	t_st	*cur;

	cur = tail_a->tail->next;
	minlst = cur;
	size = tail_a->size;
	while (size-- > 1)
	{
		if (minlst->num > cur->next->num)
			minlst = cur->next;
		cur = cur->next;
	}
	return (minlst);
}

t_st	*check_max(t_lst *tail_a, int size)
{
	t_st	*maxlst;
	t_st	*cur;

	cur = tail_a->tail->next;
	maxlst = cur;
	size = tail_a->size;
	while (size-- > 1)
	{
		if (maxlst->num < cur->next->num)
			maxlst = cur->next;
		cur = cur->next;
	}
	return (maxlst);
}

int		check_ascending(t_lst *tail_lst)
{
	t_st	*cur;
	int		size;

	cur = tail_lst->tail->next;
	size = tail_lst->size;
	while (size-- > 1)
	{
		if (cur->num > cur->next->num)
			return (1);
		cur = cur->next;
	}
	return (0);
}

