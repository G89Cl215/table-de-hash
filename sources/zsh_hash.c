/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zsh_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:36:22 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/21 23:27:15 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "zsh_hash.h"

/*
** Cette surcouche du module vise a reproduire le fonctionnnement de la table de
** hash du shell zsh.
*/

void					ft_free_zsh(void *to_free, size_t null)
{
	t_entry		*entry;

	entry = (t_entry*)to_free;
	(void)null;
	free(entry->key);
	free(entry->value);
	free(entry);
}

void					ft_print_zsh(t_list *to_print)
{
	t_hlist		*entry;

	entry = (t_hlist*)to_print;
	ft_printf("%s=%s\n", entry->content->key, entry->content->value);
}

static char				*ft_build_path(char *path, char *exec)
{
	size_t	len;
	size_t	slash;
	char	*res;

	slash = ft_strlen(path);
	len = ft_strlen(exec);
	/*ft_check_memory(*/res = (char*)malloc(len + slash + 2);
	ft_memcpy(res, path, slash);
	res[slash] = '/';
	ft_memcpy(res + slash + 1, exec, len);
	res[slash + len + 1] = '\0';
	return (res);
}

static void				ft_push_exec(t_htable *bin_table, char *dir_name)
{
	DIR				*dir_data;
	struct dirent	*file_data;
	struct stat		sb;
	char			*exec_path;

	if (!(dir_data = opendir(dir_name))) //probleme d'ouverture -> gestion d'erreur
		return ;
	while ((file_data = readdir(dir_data))) 
	{
		if (ft_strcmp(file_data->d_name, ".") 
		&& ft_strcmp(file_data->d_name, "..")
		&& !ft_get_entry(bin_table, file_data->d_name))
		{
			exec_path = ft_build_path(dir_name, file_data->d_name);
			if (stat(exec_path, &sb) >= 0 && sb.st_mode & S_IXUSR)
				ft_insert(bin_table, file_data->d_name, ft_strdup(exec_path),
																&ft_free_zsh);
			free(exec_path);
		}
	}
	closedir(dir_data);
}

void					ft_hash_path(t_htable *bin_table, char *path)
{
	static char		*hashed = NULL;
	char			**dir;
	size_t			i;

	if (!path || !bin_table)
	{
		ft_strdel(&hashed);
		return ;
	}
	if (hashed && !(ft_strcmp(path, hashed)))
		return ;
	i = 0;
	ft_empty_htable(bin_table, &ft_free_zsh);
	/*ft_check_memory(*/dir = ft_strsplit(path, ":");
	while ((dir[i]))
		ft_push_exec(bin_table, dir[i++]);
	ft_tabfree(dir);
	if (hashed)
		ft_strdel(&hashed);
	/*ft_check_memory(*/hashed = ft_strdup(path); //comment free ?
}