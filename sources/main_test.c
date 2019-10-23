/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:21:47 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/23 18:44:54 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "hash_module.h"
#include "htable_type_dispatcher.h"

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
	t_bash_hash	*ent;
	char		*path;

	i = 0;
	table = ft_init_htable(2, e_bash_entries); //on commence avec une petite table pour voir le comportement du redimensionnement de la table... Leaks notamment
//	printf("{%llu}		   a:b               {%llu}\n", table.ran_a, table.ran_b);
//	printf("{%llu}		size:\n", table.table_size);
	while ((av[i] && env[i]))
	{
		ft_insert_bash(&table, av[i], env[i], HIT);
		ent =  ft_get_entry(&table, av[i]);
		printf("{%s}   =:=   {%s}\n", env[i], ent->bin_path);
		i++;
		ft_print_sortentries(&table);
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
	ft_free_htable(&table);

//	ft_hash_path(NULL, NULL);

//	while (1) ;
	return (0);
}
