/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:43:46 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/02 15:48:33 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int len;
	int *range;

	i = 0;
	if (min >= max)
		return ((void*)0);
	len = max - min;
	if (!(range = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	while (i < len)
	{
		range[i] = min++;
		i++;
	}
	return (range);
}
