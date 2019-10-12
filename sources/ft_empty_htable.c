/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_htable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:53:29 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/12 21:56:23 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "htable.h"

void		ft_empty_htable(t_htable *htable)
{
	size_t		i;
	t_list		**table;

	i = 0;
	table = htable->table;
	while (i < htable->table_size)
	{
		if (table[i])
		{
			ft_lstdel(&(table[i]));
			table[i] = NULL;
		}
		i++;
	}
}
