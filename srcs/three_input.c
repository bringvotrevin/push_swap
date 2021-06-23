/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:21:55 by dim               #+#    #+#             */
/*   Updated: 2021/06/23 18:47:47 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		three_input(t_lst *tail_lst)
{
	t_st	*min;
	t_st	*max;
	
	min = check_min(tail_lst, 3);
	max = check_max(tail_lst, 3);
	// printf("min : %lld, max : %lld\n", min->num, max->num);
	if (min->next == max && check_ascending(tail_lst))
		sa(tail_lst);
	if (min == tail_lst->tail && check_ascending(tail_lst))
		rra(tail_lst);
	if (check_ascending(tail_lst))
		ra(tail_lst); // working
/* 	if (min->next == max && check_ascending(tail_a, tail_b))
		sa(tail_a);
	if (check_ascending(tail_a, tail_b))
		ra(tail_a);
	if (check_ascending(tail_a, tail_b))
		ra(tail_a); 
	return (0); // working!!!!!! */

/* 	if ((min->next == max || max->next->next == min))
		sa(tail_a);
	if (tail_a->tail->next->next->next == min && check_ascending(tail_a, tail_b))
		rra(tail_a);
	if (check_ascending(tail_a, tail_b))
		ra(tail_a); two_input error */

/* 	while (check_ascending(tail_a, tail_b))
	{
		if ((min->next == max) && check_ascending(tail_a, tail_b))
			sa(tail_a);
		if (check_ascending(tail_a, tail_b))
			ra(tail_a);
	} // 3 2 1 Case fail */
}

/* void	printint(int *arr, int size)
{
	int	i;
	
	i = 0; 
	while (i < size)
	{
		printf("arr[%d] : %d\n", i, arr[i]);
		i++;
	}
} */

int		more_than_five(t_lst *tail_a, t_lst *tail_b)
{
	int		*arr_s;

	arr_s = arr_forsort(tail_a);
	if (arr_s == NULL)
		return (0);
	quick_sort(0, tail_a->size - 1, arr_s);
	sort_stack(tail_a, tail_b, arr_s);
	// printint(arr_s, tail_a->size);
	if (tail_b == NULL)
		return (0); //remove it!
	return (1);
}

void	count_input(t_lst *tail_a, t_lst *tail_b)
{
	int		i;

	i = 0;
	if (tail_a->size <= 3)
		three_input(tail_a);
	else if (tail_a->size > 3 && tail_a->size <= 5)
		five_input(tail_a, tail_b);
	else if (tail_a->size > 5)
		i = more_than_five(tail_a, tail_b);	
}

int		push_swap(t_lst *tail_a)
{
	t_lst	*tail_b;

	tail_b = ft_lstnew_t();
	if (tail_b == NULL)
		return (0);
	count_input(tail_a, tail_b);
	return (1);
}
