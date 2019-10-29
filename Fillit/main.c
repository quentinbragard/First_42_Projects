/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:01:56 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/29 16:34:41 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_usage(void)
{
	ft_putstr("\n    \033[31;1mAn error occured, please check your");
	ft_putstr(" input again.\033[0m\n\nusage :  ");
	ft_putstr("\033[32;1muser@local\033[0m:\033[36;1m~/fillit\033[0m$");
	ft_putstr(" ./fillit </path/to/file>\n\n");
	ft_putstr("\tTetriminos in file are separated by a \\n.\n\n\t\t\033");
	ft_putstr("[30;1m    #\t\t\033[34;1m  #\t\033[33;1m# #\n\t\033[36;");
	ft_putstr("1m # # # #  \033[30;1m  # # #    \033[34;1m # # #    \033[");
	ft_putstr("33;1m # #\n\n\t\t \033[32;1m# #  \033[35;1m   #   \033[3");
	ft_putstr("1;1m   # #\n\t\033[32;1m       # #  \033[35;1m   # # #  ");
	ft_putstr("  \033[31;1m  # #\n\n\t\t\033[37;1m_____________________\n");
	ft_putstr("\n\t\033[37;1m  . . . .     . \033[33;1m# # \033[37;1m.   ");
	ft_putstr("  . . . .\n\t  . \033[35;1m# # #\033[37;1m     . \033[33;1");
	ft_putstr("m# # \033[37;1m.     . . . .\n\t  . . \033[35;1m#\033[37;1");
	ft_putstr("m .     . . . .     . . .   \033[0m\033[31;1m<- no dot!\n");
	ft_putstr("\033[37;1m\t  . . . .     . . . .     \033[36;1m# # # #\n ");
	ft_putstr("\n\033[32;1m\t  \xE2\x9C\x93 Valid     \xE2\x9C\x93 Valid ");
	ft_putstr("\033[31;1m    × Error\033[0m\n");
	return (-1);
}

int		main(int ac, char **av)
{
	char			**tet;
	char			**map;
	t_params		params;
	static t_point	*co;

	if (ac != 2)
		return (ft_usage());
	if (!(tet = tetrimino_checker(av[1], &params.ls)))
	{
		ft_putstr("error\n");
		return (-1);
	}
	ft_init(&map, &co, &(params.cur_line), params.ls);
	params.tet_len = ft_tablen(tet);
	while (params.cur_line < params.tet_len)
		while (!(map = fillit(map, tet, &co, &params)) && (params.ls += 1))
			ft_init(&map, &co, &(params.cur_line), params.ls);
	ft_printtab(map);
	ft_strstrdel(&map);
	ft_strstrdel(&tet);
	return (1);
}
