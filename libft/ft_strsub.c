/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:12:49 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/25 17:34:46 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;

	if (s != NULL)
	{
		result = (char *)malloc((len + 1) * sizeof(char));
		if (result == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			result[i] = s[start + i];
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	else
		return (NULL);
}
