/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_placer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:55:07 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/29 16:33:48 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		swap_line(char **tet, int line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 3)
	{
		tmp = tet[line + i + 1];
		tet[line + i + 1] = tet[line + i];
		tet[line + i] = tmp;
		i++;
	}
	return ;
}

static void		swap_column(char **tet, int line)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			tmp = tet[line + j][i];
			tet[line + j][i] = tet[line + j][i + 1];
			tet[line + j][i + 1] = tmp;
			j++;
		}
		i++;
	}
	return ;
}

static char		**map_init(int ls)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (ls + 1))))
		return (NULL);
	while (i < ls && !(j = 0))
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (ls + 1))))
			return (NULL);
		while (j < ls)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

char			**tetrimini_placer(char **tet, int line)
{
	int		count;

	count = 0;
	if (!tet[line])
		return (tet);
	while (tet[line][count] == '.')
		count++;
	if (count == 4)
	{
		swap_line(tet, line);
		return (tetrimini_placer(tet, line));
	}
	count = 0;
	while (count < 4 && tet[line + count][0] == '.')
		count++;
	if (count == 4)
	{
		swap_column(tet, line);
		return (tetrimini_placer(tet, line));
	}
	return (tetrimini_placer(tet, line + 4));
}

void			ft_init(char ***map, t_point **co, int *line, int ls)
{
	int i;

	*line = 0;
	i = 0;
	if (!*co)
	{
		if (!((*co) = malloc(sizeof(t_point) * 26)))
			return ;
	}
	while (i < 26)
	{
		((*co)[i]).x = 0;
		((*co)[i++]).y = 0;
	}
	*map = map_init(ls);
}
