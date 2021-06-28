/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 03:24:18 by dim               #+#    #+#             */
/*   Updated: 2021/06/28 11:51:57 by dim              ###   ########.fr       */
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
	while (size-- > 1)
	{
		if (maxlst->num < cur->next->num)
			maxlst = cur->next;
		cur = cur->next;
	}
	return (maxlst);
}

int		check_ascending(t_lst *tail_lst, int size)
{
	t_st	*cur;

	cur = tail_lst->tail->next;
	while (--size)
	{
		if (cur->num > cur->next->num)
			return (1);
		cur = cur->next;
	}
	return (0);
}
