/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_entries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:02:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/19 11:20:46 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "htable.h"

t_list		*ft_lstcpy(t_list *elem)
{
	t_hlist		*new;
	void		*tmp;

	new = (t_hlist*)elem;
	new->content->key = ft_strdup(new->content->key);
	tmp = ft_memalloc(new->content->value_size);
	ft_memcpy(tmp, new->content->value, new->content->value_size);
	new->content->value = tmp;
	return (elem);
}

t_hlist		*ft_lst_entries(const t_htable *htable)
{
	size_t		i;
	t_hlist		**table;
	t_hlist		*entries;

	i = 0;
	entries = NULL;
	table = htable->table;
	while (i < htable->table_size)
	{
		if (table[i])
			ft_lstadd((t_list**)&entries,
					ft_lstmap((t_list*)(table[i]), &ft_lstcpy));
		i++;
	}
	return (entries);
}
