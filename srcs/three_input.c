/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:21:55 by dim               #+#    #+#             */
/*   Updated: 2021/06/25 21:26:08 by dim              ###   ########.fr       */
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
	if (min->next == max && check_ascending(tail_lst, 3))
		sa(tail_lst);
	if (min == tail_lst->tail && check_ascending(tail_lst, 3))
		rra(tail_lst);
	if (check_ascending(tail_lst, 3))
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

}

void	printint(int *arr, int size)
{
	int	i;
	
	i = 0; 
	while (i < size)
	{
		printf("arr[%d] : %d\n", i, arr[i]);
		i++;
	}
}

void		five_input(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*min;
	t_st	*max;
	t_st	*cur;
	int		size;
	int		flag;

	size = tail_a->size;
	flag = 0;
	cur = tail_a->tail->next;
	min = check_min(tail_a, 5);
	max = check_max(tail_a, 5);
	// printf("min : %lld, max : %lld\n", min->num, max->num);
	while(size--)
	{
		if (cur == min || \
		cur == max)
		{
			cur = cur->next;
			pb(tail_a, tail_b);
			flag++;
			if (flag == 2)
				break;
		}
		else
		{
			ra(tail_a);
			cur = cur->next;
		}
	}
	three_input(tail_a);
	while (flag--)
	{
		pa(tail_a, tail_b);
		if (tail_a->tail->next == max)
			ra(tail_a);
	}
}

int		more_than_five(t_lst *tail_a, t_lst *tail_b)
{
	int		*arr;

	arr = arr_forsort(tail_a);
	quick_sort(0, tail_a->size - 1, arr);
	printint(arr, tail_a->size);
	sort_stack(tail_a, tail_b, arr);
	free(arr);
	return (1);
}

void	printst(t_lst *tail_lst)
{
	int 	i = tail_lst->size;
	t_st	*cur;
	cur = tail_lst->tail->next;
	while (i--)
	{
		printf("%lld\n", cur->num);
		cur = cur->next;
	}
}

int		push_swap(t_lst *tail_a)
{
	t_lst	*tail_b;
	int		i;

	tail_b = ft_lstnew_t();
	if (tail_b == NULL)
		return (0);
	i = 0;
	if (tail_a->size <= 3)
		three_input(tail_a);
	else if (tail_a->size > 3 && tail_a->size <= 5)
		five_input(tail_a, tail_b);
	else if (tail_a->size > 5)
		i = more_than_five(tail_a, tail_b);
	// printst(tail_a);
	free_lst(tail_b);
	if (i == 0)
		return (0);
	return (1);
}
