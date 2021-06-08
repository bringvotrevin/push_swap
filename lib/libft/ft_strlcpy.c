/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:24:19 by dim               #+#    #+#             */
/*   Updated: 2021/01/04 23:32:13 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t maxlen)
{
	size_t i;

	i = 0;
	if (src == NULL)
		return (0);
	if (dest == NULL || maxlen == 0)
		return (ft_strlen(src));
	while (src[i] && (i + 1) < maxlen)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}
