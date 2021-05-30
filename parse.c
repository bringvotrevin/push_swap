/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:26:06 by dim               #+#    #+#             */
/*   Updated: 2021/05/30 21:55:24 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char *argv[])
{
	t_st	*stack_a;
	t_st	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return 0;
	check_error();
	parse(argc, argv, &stack_a);

	return (0);
}

void	parse(int argc, char **argv, t_st **head)
{
	int		i;

	while (i < argc)
	{
		
	}
}

 void	sa()