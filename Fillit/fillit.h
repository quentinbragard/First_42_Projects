/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:04:09 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/05/01 18:59:14 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define MAX_SIZE 546

typedef struct		s_point
{
	int					x;
	int					y;
}					t_point;

typedef struct		s_params
{
	int					ls;
	int					cur_line;
	int					tet_len;

}					t_params;

char				**tetrimino_checker(const char *input, int *ls);
char				**tetrimini_placer(char **tet, int line);
char				**fillit(char **map, char **tet, t_point **co,
		t_params *params);
void				ft_init(char ***map, t_point **co, int *line, int ls);
int					ft_sqrt(int nb);
int					ft_tablen(char **tab);
void				ft_printtab(char **tab);
void				ft_strstrdel(char ***tab);

#endif
