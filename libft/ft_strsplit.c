/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:14:28 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/26 14:42:12 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	count_the_number_of_words_in_s(char const *s, char c)
{
	unsigned int	result;
	size_t			i;

	result = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (s[i]) != '\0')
			i++;
		if (s[i] != '\0')
			result++;
		while ((s[i] != c) && (s[i]) != '\0')
			i++;
	}
	return (result);
}

static char			**main_part_cut_here(char ***result, char const **s, int c)
{
	size_t	l_word;
	int		i_r;
	int		i_s;

	i_s = ft_strlen((char *)*s) - 1;
	i_r = count_the_number_of_words_in_s(*s, c);
	*result = (char **)malloc((i_r + 1) * sizeof(char *));
	if (*result == NULL)
		return (NULL);
	(*result)[i_r] = NULL;
	while (i_r > 0)
	{
		while ((i_s >= 0) && ((*s)[i_s] == c))
			i_s--;
		l_word = 0;
		while ((i_s >= 0) && ((*s)[i_s] != c))
		{
			l_word++;
			i_s--;
		}
		(*result)[--i_r] = ft_strsub((*s), (unsigned int)(i_s + 1), l_word);
	}
	return (*result);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**result;

	if (s != NULL)
		return (main_part_cut_here(&result, &s, c));
	else
		return (NULL);
}
