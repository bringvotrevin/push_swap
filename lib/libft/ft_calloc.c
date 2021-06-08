/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 02:37:09 by dim               #+#    #+#             */
/*   Updated: 2020/12/28 03:57:19 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*arr;
	size_t	i;

	arr = (char *)malloc(n * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < n * size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
