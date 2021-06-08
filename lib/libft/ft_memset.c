/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:02:27 by dim               #+#    #+#             */
/*   Updated: 2020/12/25 05:23:50 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = (unsigned char)value;
		i++;
	}
	return (dest);
}
