/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_htable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:32:53 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/12 21:56:28 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "htable.h"

void		ft_iter_htable(t_htable *htable, t_ft_list to_apply)
{
	size_t		i;
	t_list		**table;

	i = 0;
	table = htable->table;
	while (i < htable->table_size)
	{
		if (table[i])
			ft_lstiter(table[i], to_apply);
		i++;
	}
}
