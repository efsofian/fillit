/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enanrock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:58:28 by enanrock          #+#    #+#             */
/*   Updated: 2017/02/03 01:50:17 by enanrock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_mem_ttmn
{
	int			lock[26][4];
	int			length;
	int			limite;
	int			number_ttmn;
}				t_mem_ttmn;

#endif
