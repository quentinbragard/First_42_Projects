/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:20:45 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/04 18:32:00 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	if (nb > 12)
		return (0);
	else
	{
		nb = nb * ft_factorial(nb - 1);
		return (nb);
	}
}
