/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 15:43:50 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/19 18:01:32 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;

	i = 0;
	dst_size = 0;
	if (size > 0)
	{
		while (i < size && dst[i] != '\0')
			i++;
		dst_size = i;
		i = 0;
		if (dst_size < size)
		{
			while (dst_size + i < size - 1 && src[i] != '\0')
			{
				dst[i + dst_size] = src[i];
				i++;
			}
			dst[i + dst_size] = '\0';
		}
	}
	while (src[i] != '\0')
		i++;
	return (i + dst_size);
}
