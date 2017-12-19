/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:22:04 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/24 16:57:43 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	while (s1[i1] != '\0')
		i1++;
	i2 = 0;
	while (s2[i2] != '\0')
	{
		s1[i1 + i2] = s2[i2];
		i2++;
	}
	s1[i1 + i2] = '\0';
	return (s1);
}