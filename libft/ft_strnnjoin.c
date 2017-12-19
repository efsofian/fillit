/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 14:43:09 by enanrock          #+#    #+#             */
/*   Updated: 2017/01/01 15:51:02 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnnjoin(char const *s1, char const *s2, size_t len1, size_t len2)
{
	char	*r12;
	size_t	i;
	size_t	len_r12;

	if ((s1 != NULL) && (s2 != NULL))
	{
		len_r12 = len1 + len2;
		r12 = (char *)malloc((len_r12 + 1) * sizeof(char));
		if (r12 == NULL)
			return (NULL);
		i = 0;
		r12 = ft_memmove(r12, s1, len1);
		ft_strncat(r12, s2, len_r12);
		return (r12);
	}
	else
		return (NULL);
}
