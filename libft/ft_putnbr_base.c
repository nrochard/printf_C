/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:26:22 by nrochard          #+#    #+#             */
/*   Updated: 2019/12/20 19:02:25 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>


static void		reverse_stock(t_list *l)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(l->stock);
	tmp = malloc(sizeof(char) * (size + 1));
	tmp = l->stock;
	l->stock = NULL;
	l->stock = malloc(sizeof(char) * (size + 1));
	tmp[size] = '\0';
	while (size > 0)
	{
		l->stock[i] = tmp[size - 1];
		i++;
		size--;
	}
	l->stock[i] = '\0';
}

static void		reverse_stock_p(t_list *l)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(l->stock) + 2;
	tmp = malloc(sizeof(char) * (size + 1));
	tmp = l->stock;
	l->stock = NULL;
	l->stock = malloc(sizeof(char) * (size + 1));
	tmp[size] = '\0';
	while (size > 0)
	{
		l->stock[i] = tmp[size - 1];
		i++;
		size--;
	}
	l->stock[0] = '0';
	l->stock[1] = 'x';
	l->stock[i] = '\0';
}

void	ft_putnbr_p(uintmax_t nbr, char *base, t_list *l)
{
	unsigned int	a;
	int             size;

	size = 0;	
	if (nbr == 0)
	{
		l->stock = ft_manage_zero(l);
		return ;
	}
	a = nbr;
	while (a > 16)
	{
		a = a / 16;
		size++;
	}
	l->stock = malloc(sizeof(char) * (size + 2));
	size = 0;
	while (nbr > 16)
	{
		if (nbr < 16)
			l->stock[size] = base[nbr];
		else
			l->stock[size] = base[nbr % 16];
		size++;
		nbr = nbr / 16;
	}
	if (nbr < 16)
		l->stock[size] = base[nbr];
	else
		l->stock[size] = base[nbr % 16];
	size++;
	l->stock[size] = '\0';
	reverse_stock_p(l);
}
 
void	ft_putnbr_base(unsigned int nbr, char *base, t_list *l)
{
	unsigned int	a;
	int             size;

	size = 0;
	if (nbr == 0)
	{
		l->stock = ft_manage_zero(l);
		return ;
	}
	a = nbr;
	while (a > 16)
	{
		a = a / 16;
		size++;
	}
	l->stock = malloc(sizeof(char) * (size + 1));
	size = 0;
	while (nbr > 16)
	{
		if (nbr < 16)
			l->stock[size] = base[nbr];
		else
			l->stock[size] = base[nbr % 16];
		size++;
		nbr = nbr / 16;
	}
	if (nbr < 16)
		l->stock[size] = base[nbr];
	else
		l->stock[size] = base[nbr % 16];
	size++;
	l->stock[size] = '\0';
	reverse_stock(l);
}
