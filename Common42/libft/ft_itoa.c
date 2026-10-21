/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoudic <mtoudic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:04:26 by mtoudic           #+#    #+#             */
/*   Updated: 2026/10/21 11:28:36 by mtoudic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	*nstr;
	size_t	i;
	int		sign;

	nstr = malloc(12 * sizeof(char));
	if (!nstr)
		return (NULL);
	sign = 1;
	if (n < 0)
		sign = -1;
	nstr[11] = '\0';
	i = 10;
	while (1)
	{
		nstr[i--] = (n % 10) * sign + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	if (sign == -1)
		nstr[i] = '-';
	else
		i++;
	ft_memmove(nstr, nstr + i, 12 - i);
	return (nstr);
}
