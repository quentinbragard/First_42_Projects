/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:43:12 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/29 16:33:38 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		file_checker(char *str, int len)
{
	int count[3];
	int i;
	int j;

	j = 0;
	while (j < len && !(count[0] = 0))
	{
		count[1] = 0;
		count[2] = 0;
		i = -1;
		while (++i < 20 && i + j < len)
		{
			if (str[i + j] == '\n' && (count[0] += 1))
				if (count[0] <= 4 && (i + 1) % 5 != 0)
					return (0);
			if (str[i + j] == '#')
				count[1]++;
			if (str[i + j] == '.')
				count[2]++;
		}
		if (count[0] != 4 || count[1] != 4 || count[2] != 12)
			return (0);
		j += 21;
	}
	return (1);
}

static char		*convert_letters(char *str, int len)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	c = 'A';
	while (j < len)
	{
		i = 0;
		while (i < 20 && i + j < len)
		{
			if (str[i + j] == '#')
				str[i + j] = c;
			i++;
		}
		j += 21;
		c++;
	}
	return (str);
}

static int		count_connection(char **tab, int i, int j, int next)
{
	int count;

	count = 0;
	if (i != 0 && tab[next + j][i - 1] != '.' && tab[next + j][i - 1] != '\n')
		count++;
	if (i != 3 && tab[next + j][i + 1] != '.' && tab[next + j][i + 1] != '\n')
		count++;
	if (j != 0 && tab[next + j - 1][i] != '.' && tab[next + j][i] != '\n')
		count++;
	if (j != 3 && tab[next + j + 1][i] != '.' && tab[next + j][i] != '\n')
		count++;
	return (count);
}

static char		**connections_checker(const char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		next;
	int		connections;

	if (!(tab = ft_strsplit(str, '\n')))
		return (NULL);
	j = 0;
	next = 0;
	while (tab[next] && !(connections = 0))
	{
		j = 0;
		while (j < 4 && tab[next + j] && (i = -1))
		{
			while (++i < 4)
				if (tab[next + j][i] != '.' && tab[next + j][i] != '\n')
					connections += count_connection(tab, i, j, next);
			j++;
		}
		if (connections < 6)
			return (NULL);
		next += 4;
	}
	return (tab);
}

char			**tetrimino_checker(const char *path, int *ls)
{
	char	buf[MAX_SIZE + 1];
	char	**tab;
	int		fd;
	int		rd;

	fd = open(path, O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) == -1)
		return (NULL);
	rd = read(fd, buf, MAX_SIZE + 1);
	if (rd == MAX_SIZE + 1 || rd < 20 || rd % 21 != 20)
		return (NULL);
	buf[rd] = '\0';
	if (!file_checker(buf, rd))
		return (NULL);
	tab = connections_checker(convert_letters(buf, rd));
	*ls = (rd / 21 + 1) * 4;
	while (!ft_sqrt(*ls))
		*ls += 1;
	*ls = ft_sqrt(*ls);
	if (*ls < 4)
		*ls = 2;
	if (tab)
		tab = tetrimini_placer(tab, 0);
	return (tab);
}
