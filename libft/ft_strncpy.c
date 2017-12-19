/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:45:59 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/24 16:46:09 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((i < len) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	if (i == len - 1)
		dest[i] = '\0';
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
