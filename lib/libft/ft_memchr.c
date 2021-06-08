/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:57:53 by dim               #+#    #+#             */
/*   Updated: 2020/12/28 01:38:42 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chr;
	size_t			i;

	chr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (chr[i] == (unsigned char)c)
			return ((void *)&chr[i]);
		i++;
	}
	return (NULL);
}
