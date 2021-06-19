/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ids <ids@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:21:55 by dim               #+#    #+#             */
/*   Updated: 2021/06/20 02:13:45 by ids              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_util.h"


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

int		check_ascending(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*cur;
	int		size;

	if (tail_b)
	cur = tail_a->tail->next;
	size = tail_a->size;
	while (size-- > 1)
	{
		if (cur->num > cur->next->num)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void		three_input(t_lst *tail_a, t_lst *tail_b)
{
	t_st	*min;
	t_st	*max;
	
	min = check_min(tail_a, 3);
	max = check_max(tail_a, 3);
	// printf("min : %lld, max : %lld\n", min->num, max->num);
	if (min->next == max && check_ascending(tail_a, tail_b))
		sa(tail_a);
	if (min == tail_a->tail && check_ascending(tail_a, tail_b))
		rra(tail_a);
	if (check_ascending(tail_a, tail_b))
		ra(tail_a); // working
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

void		int_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void		sort(int left, int right, int *arr)
{
	int		pivot;
	int		i;
	int		j;

	i = left;
	j = right;
	pivot = arr[(left + right) / 2];
	if (left < right)
	{
		while (i <= j)
		{
			while (arr[i] < pivot)
				i++;
			while (arr[j] > pivot)
				j--;
			if (i <= j)
			{
				int_swap(&(arr[i]), &(arr[j]));
				i++;
				j--;
			}
		}
		sort(left, j, arr);
		sort(i, right, arr);
	}
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
	int		*arr;
	int		*arr_s;

	arr = arr_forsort(tail_a);
	arr_s = arr_forsort(tail_a);
	if (arr == NULL || arr_s == NULL)
		return (0);
	sort(0, tail_a->size - 1, arr_s);
	// printint(arr_s, tail_a->size);
	if (tail_b == NULL)
		return (0); //remove it!
	return (1);
}

int		*arr_forsort(t_lst *tail_lst)
{
	t_st	*cur;
	int		*arr;
	int		i;
	int		size;

	i = 0;
	size = tail_lst->size;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	cur = tail_lst->tail->next;
	while (i < size)
	{
		arr[i++] = cur->num;
		cur = cur->next;
	}
	return (arr);
}

void	count_input(t_lst *tail_a, t_lst *tail_b)
{
	int		i;

	i = 0;
	if (tail_a->size <= 3)
		three_input(tail_a, tail_b);
	else if (tail_a->size > 3 && tail_a->size <= 5)
		five_input(tail_a, tail_b);
	else if (tail_a->size > 5)
		i = more_than_five(tail_a, tail_b);
/* 	else if (tail_a->size )
		hundred_input(tial_a, tail_b);
	else if (tail_a->size >= 500)
		fivehundred_input(tail_a, tail_b); */
	
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
