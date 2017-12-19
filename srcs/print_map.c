/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:39:28 by seliasbe          #+#    #+#             */
/*   Updated: 2017/02/08 18:16:29 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_map.h"

char	*ft_pretrad(t_mem_ttmn *mem)
{
	int		i;
	int		j;
	int		l;
	char	*result;

	if ((result = (char *)malloc(sizeof(char) * ((mem->limite) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < mem->limite)
		result[i++] = '.';
	j = -1;
	while (j < mem->limite)
		result[j += mem->length + 1] = '\n';
	l = 0;
	while (l < mem->number_ttmn)
	{
		result[mem->lock[l][0]] = 'A' + l;
		result[mem->lock[l][1]] = 'A' + l;
		result[mem->lock[l][2]] = 'A' + l;
		result[mem->lock[l][3]] = 'A' + l;
		l++;
	}
	result[i] = '\0';
	return (result);
}
/*
**  void	ft_color(char *str)
**{
**  	int		i;
**  	i = 0;
**  	while (str[i])
**  	{
**  		if (str[i] == '.' || str[i] == '\n')
**  			ft_putchar(str[i]);
**  		else if (str[i] == 'A')
**  		{
**  			ft_putstr("\033[32m");
**  			ft_putchar(str[i]);
**  			ft_putstr("\033[0m");
**  		}
**  		else if (str[i] == 'B')
**  		{
**  			ft_putstr("\033[33m");
**  			ft_putchar(str[i]);
**  			ft_putstr("\033[0m");
**  		}
**  		else if (str[i] == 'C')
**  		{
**  			ft_putstr("\033[34m");
**  			ft_putchar(str[i]);
**  			ft_putstr("\033[0m");
**  		}
**  		else if (str[i] == 'D')
**  		{
**  			ft_putstr("\033[35m");
**  			ft_putchar(str[i]);
**  			ft_putstr("\033[0m");
**  		}
**  		else if (str[i] == 'E')
**  		{
**  			ft_putstr("\033[36m");
**  			ft_putchar(str[i]);
**  			ft_putstr("\033[0m");
**  		}
**  		else if (str[i] == 'F')
**  		{
**  			ft_putstr("\033[37m");
**  			ft_putchar(str[i]);
**  			ft_putstr("\033[0m");
**  		}
**  		else
**  			ft_putchar(str[i]);
**  		i++;
**  	}
**  }
*/
