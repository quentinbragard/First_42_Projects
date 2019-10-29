/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:30:41 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/01 12:33:36 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if ((s1[i] == '\0') && (s2[i] == '\0'))
			return (0);
		if ((s1[i] == '\0') || (s2[i] == '\0'))
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int		ft_count(char *s1, int ac, char **av)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		if (ft_strcmp(s1, av[i]) >= 0)
			k++;
		i++;
	}
	return (k);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 1)
		return (0);
	i = 1;
	j = 1;
	while (i < argc)
	{
		while (j < argc)
		{
			if (ft_count(argv[j], argc, argv) == i)
				ft_putstr(argv[j]);
			j++;
		}
		i++;
		j = 1;
	}
	return (0);
}
