/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:38:47 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/23 14:58:39 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bash_hash.h"

void	ft_free_bash_hash(void *to_free, size_t null)
{
	t_entry		*entry;

	entry = (t_entry*)to_free;
	(void)null;
	free(entry->key);
	free(((t_bash_hash*)(entry->value))->bin_path);
	free(entry->value);
	free(entry);
}

void	ft_insert_bash_hash(t_htable *htable, char *key,
												char *path, unsigned int hit)
{
	t_bash_hash		*new;

	/*ft_check_memory(*/new = ft_memalloc(sizeof(t_bash_hash));
	new->bin_path = ft_strdup(path);
	new->hit_value = hit;
	ft_insert(htable, key, new);
}

void	ft_print_bash_hash(t_list *to_print)
{
	t_bash_hash		*entry;
	char			*print_text;

	entry = ((t_hlist*)to_print)->content->value;
	if (entry->hit_value < 10000)
		print_text = "%4u    %s\n";
	else// if (entry->hit_value < 1000000)
		print_text = "%-8u%s\n";
	ft_printf(print_text, entry->hit_value, entry->bin_path);
}
