/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:23:53 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/01 15:20:09 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int n;

	i = 1;
	n = 1;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	if (nb > 12)
		return (0);
	else
	{
		while (i <= nb)
		{
			n = n * i;
			i++;
		}
	}
	return (n);
}
