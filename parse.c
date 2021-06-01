/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:26:06 by dim               #+#    #+#             */
/*   Updated: 2021/06/01 19:21:50 by dim              ###   ########.fr       */
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
	int		i;
	char	*num;

	i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		new = ft_lstnew(num);
		ft_lstadd_tail(tail_a, new); 
	}
}

void	ft_lstadd_tail(t_lst *tail_lst, t_st *lst)
{
	if (tail_lst == NULL || lst = NULL)
		return ;
	if (tail_lst->tail == NULL)
		tail_lst->tail = lst;
	else
	{
		tail_lst->tail->next = lst;
		tail_lst->tail = lst;
	}
}

 void	sa(tail_a)
{

