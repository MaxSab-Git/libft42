/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 12:58:51 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/22 20:29:40 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	start;
	size_t	i;

	start = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (start < len && big[start] != '\0')
	{
		i = 0;
		while (start + i < len && little[i] && little[i] == big[i + start])
			i++;
		if (little[i] == '\0')
			break ;
		start++;
	}
	if (big[start] == '\0' || start >= len)
		return (NULL);
	return ((char *)big + start);
}
