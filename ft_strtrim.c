/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:40:00 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/22 19:39:28 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trim_start;
	size_t	trim_end;
	char	*trimmed;

	trim_start = 0;
	trim_end = ft_strlen(s1);
	while (s1[trim_start] != '\0' && ft_strchr(set, s1[trim_start]) != NULL)
		trim_start++;
	while (trim_end > trim_start && ft_strchr(set, s1[trim_end - 1]) != NULL)
		trim_end--;
	trimmed = malloc((trim_end - trim_start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + trim_start,
		(trim_end - trim_start + 1) * sizeof(char));
	return (trimmed);
}
