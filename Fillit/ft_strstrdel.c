/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:02:09 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/29 16:34:23 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_strstrdel(char ***tab)
{
	int i;

	i = 0;
	if (!(*tab))
		return ;
	while ((*tab)[i])
		ft_strdel(&(*tab)[i++]);
	free(*tab);
	*tab = NULL;
}
