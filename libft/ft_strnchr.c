/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:27:43 by enanrock          #+#    #+#             */
/*   Updated: 2017/01/03 18:44:54 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnchr(const char *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while ((i < len) && (s[i] != (char)c) && (s[i] != '\0'))
		i++;
	if (((char)c != '\0') && (s[i] == '\0'))
		return (NULL);
	return ((char *)(s + i));
}
