/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:34:03 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/21 18:04:18 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n && ((unsigned char *)s)[i] != *(unsigned char *)&c)
		i++;
	if (i >= n)
		return (NULL);
	return (&((unsigned char *)s)[i]);
}
