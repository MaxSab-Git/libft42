/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:59:47 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/22 20:27:15 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	truelen;
	char	*sub;

	truelen = ft_strlen(s);
	if (start > truelen)
		truelen = 0;
	else
		truelen = ft_strlen(s + start);
	if (truelen > len)
		truelen = len;
	sub = malloc((truelen + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, truelen);
	sub[truelen] = '\0';
	return (sub);
}
