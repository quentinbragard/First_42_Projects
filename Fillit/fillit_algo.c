/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:03:10 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/29 16:33:27 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		pos_checker(char **tab, char **map, t_params *params,
		t_point co)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < 4 && (j = -1))
	{
		while (++j < 4)
		{
			if (tab[(*params).cur_line + i][j] != '.')
			{
				if (co.y >= (*params).ls || co.x >= (*params).ls
						|| map[co.y][co.x] != '.')
					return (0);
				if (++count == 4)
					return (1);
			}
			co.x++;
		}
		co.y++;
		co.x -= 4;
	}
	return (1);
}

static char		**map_filler(char **tab, char **map, t_point co, int line)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[line + i][j] != '.')
			{
				map[co.y][co.x] = tab[line + i][j];
				if (++count == 4)
					return (map);
			}
			j++;
			co.x++;
		}
		i++;
		co.y++;
		co.x -= 4;
	}
	return (map);
}

static char		**map_defiller(char **map, t_params params)
{
	int		i;
	int		j;
	int		count;
	char	c;

	i = 0;
	count = 0;
	c = 'A' + (params.cur_line / 4);
	while (i < params.ls)
	{
		j = 0;
		while (j < params.ls)
		{
			if (map[i][j] == c)
			{
				map[i][j] = '.';
				if (++count == 4)
					return (map);
			}
			j++;
		}
		i++;
	}
	return (map);
}

static int		pos_increment(t_point **co, t_params *params)
{
	if ((*co)[(*params).cur_line / 4].x < (*params).ls)
	{
		(*co)[(*params).cur_line / 4].x += 1;
		return (1);
	}
	else if ((*co)[(*params).cur_line / 4].y < (*params).ls)
	{
		(*co)[(*params).cur_line / 4].x = 0;
		(*co)[(*params).cur_line / 4].y += 1;
		if ((*co)[(*params).cur_line / 4].y != 4)
			return (1);
	}
	if ((*co)[(*params).cur_line / 4].y == (*params).ls)
	{
		(*co)[(*params).cur_line / 4].x = 0;
		(*co)[(*params).cur_line / 4].y = 0;
		(*params).cur_line -= 4;
		return ((*params).cur_line >= 0 ? 0 : 1);
	}
	return (1);
}

char			**fillit(char **map, char **tet, t_point **co,
		t_params *params)
{
	int j;

	j = 0;
	while (!pos_checker(tet, map, params, (*co)[(*params).cur_line / 4]))
	{
		if (!pos_increment(co, params))
		{
			map = map_defiller(map, *params);
			pos_increment(co, params);
			return (map);
		}
		if ((*params).cur_line < 0)
		{
			ft_strstrdel(&map);
			return (map);
		}
	}
	map = map_filler(tet, map, (*co)[(*params).cur_line / 4],
			(*params).cur_line);
	(*params).cur_line += 4;
	if (!tet[(*params).cur_line])
		return (map);
	return (fillit(map, tet, co, params));
}
