/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:31:18 by enanrock          #+#    #+#             */
/*   Updated: 2016/11/29 15:53:05 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*alst_next;

	if (alst != NULL)
	{
		while (*alst != NULL)
		{
			alst_next = (**alst).next;
			ft_lstdelone(alst, del);
			if (alst_next != NULL)
				ft_lstdel(&alst_next, del);
		}
	}
}
