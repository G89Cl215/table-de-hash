/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:21:47 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/28 17:42:49 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "hash_module.h"

int		main(int ac, char **av, char **env)
{
	int			i;
	t_htable	table;

	i = 0;
	table = ft_init_htable(DEF_SIZE);
//	printf("{%llu}   a:b   {%llu}\n", table.ran_a, table.ran_b);
	while ((av[i] && env[i]))
	{
		ft_insert(&table, av[i], env[i]);
//		printf("{%s}   =:=   {%s}\n", env[i], ft_get_entry(&table, av[i]));
		
		i++;
	}
	ft_free_htable(&table);
	return (0);
}

//uint64_t		ft_eratosthene(uint64_t nbr);
//int				ft_miller_rabin(uint64_t to_test, uint64_t k);
//int		main(int ac, char **argv)
//{
//	uint64_t num;
//	uint64_t i;
//	uint64_t prime;
//
//	i = 10000;
//	num = 3102520049;
//	while (i--)
//	{
//		//prime = ft_eratosthene(num);
//		prime = ft_miller_rabin(num, 4);
//		if (prime)
//			printf("%llu is prime\n", num);
//		else
//			printf("%llu\n", num);
//	}
//}
