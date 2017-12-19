/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:39:56 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/27 19:21:09 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_dst;
	size_t	i_src;

	i_dst = 0;
	while ((i_dst < size) && (dst[i_dst] != '\0'))
		i_dst++;
	i_src = 0;
	while (((i_dst + i_src) < (size - 1)) && (src[i_src] != '\0'))
	{
		dst[i_dst + i_src] = src[i_src];
		i_src++;
	}
	if ((i_dst + i_src) < size)
		dst[i_dst + i_src] = '\0';
	return (i_dst + ft_strlen((char *)src));
}
