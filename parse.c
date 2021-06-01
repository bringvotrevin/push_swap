/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:26:06 by dim               #+#    #+#             */
/*   Updated: 2021/06/01 11:48:28 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_lst	tail_a;
	t_lst	tail_b;

	tail_a = NULL;
	if (argc < 2)
		return (0);
	check_error();
	parse(argc, argv, &tail_a);
	return (0);
}

void	parse(int argc, char **argv, t_st *tail_a)
{
	t_st	*newn;
	int		i;
	char	*num;

	i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		stack_a = ft_lstnew(num);
		ft_lstadd_tail(tail_a, new); 
	}
	tail_a->tail = stack_a;
}

void	ft_lstadd_tail(t_st *tail, t_st *stack_a)
{
	if (tail == NULL || stack_a = NULL)
		return ;
	tail->next = stack_a;
	*tail = stack_a;

 void	sa(tail_a)
 {

