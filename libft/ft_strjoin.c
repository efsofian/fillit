/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:51:26 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/25 17:36:19 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	size_result;

	if ((s1 != NULL) && (s2 != NULL))
	{
		size_result = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		result = (char *)malloc((size_result + 1) * sizeof(char));
		if (result == NULL)
			return (NULL);
		i = 0;
		result = ft_strdup((char *)s1);
		ft_strcat(result, s2);
		return (result);
	}
	else
		return (NULL);
}
