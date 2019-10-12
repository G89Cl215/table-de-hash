/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 12:52:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/13 01:20:40 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_module.h"

static t_htable		ft_resize_htable(t_htable *htable)
{
	t_htable	new_table;
	t_hlist		*entries;
	t_hlist		*voyager;

	entries = ft_lst_entries(htable);
	new_table = ft_init_htable(htable->table_size * 2);
	ft_free_htable(htable);
	voyager = entries;
	while (voyager)
	{
		ft_insert(&new_table, voyager->content->key, voyager->content->value);
		voyager = voyager->next;
	}
	ft_lstdel((t_list**)&entries, &ft_free_s_entry);
	return (new_table);
}

void				ft_insert(t_htable *htable, char *key, char *value)
{
	size_t		index;
	t_entry		content;
	t_hlist		*new_entry;

	content.key = ft_strdup(key);
	content.value = ft_strdup(value);
	/*ft_check_memory(*/new_entry = (t_hlist*)ft_lstnew(&content, sizeof(content));
	index = ft_hash(htable, key);
	ft_lstadd((t_list**)&(htable->table[index]), (t_list*)new_entry);
	(htable->entry_nbr)++;
	if (htable->entry_nbr * 100 / htable->table_size > 70)
		*htable = ft_resize_htable(htable);
}
