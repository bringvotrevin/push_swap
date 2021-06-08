/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:47:25 by dim               #+#    #+#             */
/*   Updated: 2021/06/06 19:22:56 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		**ft_memerror(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int			ft_free(char *str)
{
	free(str);
	return (0);
}

int			find_size(char const *s, char c)
{
	int		i;
	int		size;
	char	*arr;
	char	set[2];

	set[0] = c;
	set[1] = '\0';
	arr = ft_strtrim(s, set);
	if (arr == NULL || *arr == '\0')
		return (ft_free(arr));
	i = 0;
	size = 1;
	while (arr[i])
	{
		if (arr[i] == c)
		{
			size++;
			while (arr[i] == c)
				i++;
		}
		i++;
	}
	ft_free(arr);
	return (size);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**arr;

	if (s == NULL)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (find_size(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (i < find_size(s, c))
	{
		len = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j++] != c) 
			len++;
		if (!(arr[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (ft_memerror(arr));
		ft_strlcpy(arr[i], s + j - len - 1, len + 1);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
