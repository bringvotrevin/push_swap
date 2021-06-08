/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 02:49:53 by dim               #+#    #+#             */
/*   Updated: 2021/01/04 22:50:33 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *cur;
	t_list *cur2;

	if (lst == NULL)
		return ;
	cur = *lst;
	while (cur)
	{
		cur2 = cur->next;
		ft_lstdelone(cur, del);
		cur = cur2;
	}
	*lst = NULL;
}
