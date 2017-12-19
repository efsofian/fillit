/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:29:49 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/29 17:38:45 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  static void real_ft_put_fd(int n, int fd)
**  {
**  	char	*n_temp;
**
**  	n_temp = itoa(n);
**  	ft_putstr_fd(n_temp, fd);
**  	ft_strdel(n_temp);
**  }
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	result[12];
	int		is_negative;
	size_t	len_result;
	int		temp_n;

	ft_memset(result, '\0', 12 * sizeof(char));
	is_negative = (n < 0) ? 1 : 0;
	n *= (n < 0) ? 1 : -1;
	len_result = ((n == 0) ? 1 : 0) + is_negative;
	temp_n = n;
	while (temp_n != 0)
	{
		len_result++;
		temp_n /= 10;
	}
	while (len_result > 0)
	{
		result[--len_result] = '0' - (n % 10);
		n /= 10;
	}
	if (is_negative == 1)
		result[0] = '-';
	ft_putstr_fd(result, fd);
}
