/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:21:47 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/21 17:21:07 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "hash_module.h"
#include "bash_hash.h"

int64_t ft_used_cell(t_htable *htable)
{
	size_t		i;
	int64_t		ret;
	t_hlist		**table;

	i = 0;
	ret = 0;
	table = htable->table;
	while (i< htable->table_size)
	{
		if (table[i])
			ret++;
		i++;
	}
	return (ret);
}

int		main(int ac, char **av, char **env)
{
	int			i;
	t_htable	table;
	t_bash_hash	new;
	t_bash_hash	*ent;
	char		*path;

	i = 0;
	table = ft_init_htable(2); //on commence avec une petite table pour voir le comportement du redimensionnement de la table... Leaks notamment
//	printf("{%llu}		   a:b               {%llu}\n", table.ran_a, table.ran_b);
//	printf("{%llu}		size:\n", table.table_size);
	while ((av[i] && env[i]))
	{
		new = ft_init_bash_hash(env[i], i);
		printf("new->bin_path: |%s|", new.bin_path);
		ft_insert(&table, av[i], &new, sizeof(t_bash_hash));
		ent = ft_get_entry(&table, av[i]);
		printf("{%s}   =:=   {%s}\n", env[i], ent->bin_path);
		
		i++;
	}
//	while (env[i])
//	{
//		if (!ft_strncmp(env[i], "PATH=", 5))
//		{
//			path = strdup(env[i] + 5);
//			break ;
//		}
//		i++;
//	}
//	printf("{%s}\n", path);
//	ft_hash_path(&table, path);
//	printf("{%llu}		size:spread_factor   {%llu}\n", table.table_size, (ft_used_cell(&table) * 100)/ table.entry_nbr );
	ft_print_sortentries(&table, &ft_print_bash_hash);
//	ft_free_htable(&table);
//
//	ft_hash_path(NULL, NULL);

	return (0);
}
