/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:04:54 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/25 17:17:09 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striter(char *s, void (*f)(char *))
{
	char	*s_plus_i;
	int		i;

	if ((s != NULL) && (f != NULL))
	{
		i = 0;
		while (s[i] != '\0')
		{
			s_plus_i = s + i * sizeof(char);
			f(s_plus_i);
			i++;
		}
	}
}
