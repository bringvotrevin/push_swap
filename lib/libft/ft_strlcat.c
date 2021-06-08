/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:07:02 by dim               #+#    #+#             */
/*   Updated: 2021/01/04 23:21:07 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t maxlen)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	j = 0;
	r = 0;
	if (dest == NULL && src != NULL && maxlen == 0)
		return (ft_strlen(src));
	if (ft_strlen(dest) > maxlen)
		return (ft_strlen(src) + maxlen);
	while (dest[i])
		i++;
	while (src[j])
		j++;
	while (src[r] && i + 1 < maxlen)
	{
		dest[i++] = src[r];
		r++;
	}
	dest[i] = '\0';
	return ((i - r) + j);
}
