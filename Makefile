# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 22:11:12 by tgouedar          #+#    #+#              #
#    Updated: 2019/10/23 18:10:27 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFILE			=	corps_fini_tools.c \
					ft_empty_htable.c\
					ft_free_htable.c\
					ft_lst_entries.c\
					ft_get_entry.c\
					ft_hash.c\
					ft_insert.c\
					ft_iter_htable.c\
					ft_print_entries.c\
					init_htable.c\
					ft_hash_path.c\
					string_routines.c\
					bash_routines.c\
					htable_type_dispatcher.c\

SRC_DIR			=	sources

HDR_DIR			=	includes \
					../libft/includes \

OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRCFILE:.c=.o))

NAME			=	maths_module.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g3
HFLAGS			=	$(addprefix -I ,$(HDR_DIR))
CFLAGS			+=	$(HFLAGS)
.PHONY: all re clean fclean ls

all				: $(NAME)

$(NAME)			: $(OBJ) Makefile
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	gcc $(SRC_DIR)/main_test.c maths_module.a ../libft/libft.a $(HFLAGS)
	@echo "Your LIBFT is ready for use."

$(OBJ)			: $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/$*.o -c $<
	@echo "\t\t\t\t\t\t\t\t[OK]\r\t$*"

$(OBJ_DIR)		:
	@/bin/mkdir -p $(OBJ_DIR)


clean			:
	@/bin/rm -Rf $(OBJ_DIR) 2>/dev/null || true

fclean			: clean
	@/bin/rm -f $(NAME)

re				: fclean all
