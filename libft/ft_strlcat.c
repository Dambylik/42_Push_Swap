/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:45:57 by okapshai          #+#    #+#             */
/*   Updated: 2024/08/14 17:45:59 by okapshai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;
	size_t	offst;

	dst_len = str_len(dest);
	src_len = str_len(src);
	offst = dst_len;
	i = 0;
	if (dst_len >= size)
		return (src_len + size);
	while (src[i] != '\0' && i < size - dst_len - 1)
	{
		dest[offst] = src[i];
		offst++;
		i++;
	}
	dest[offst] = '\0';
	return (dst_len + src_len);
}
