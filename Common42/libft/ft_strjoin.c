/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:23:55 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/20 15:36:50 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*join;

	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(total_size * sizeof(char));
	if (!join)
		return (NULL);
	join[0] = '\0';
	ft_strlcat(join, s1, total_size);
	ft_strlcat(join, s2, total_size);
	return (join);
}
