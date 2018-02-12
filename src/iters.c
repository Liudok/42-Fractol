/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iters.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 17:32:03 by lberezyn          #+#    #+#             */
/*   Updated: 2018/01/02 17:37:24 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			ft_find_i(t_gra *o, int two)
{
	int		i;

	i = -1;
	while (++i < o->max_iter && (o->z_re * o->z_re + o->z_im * o->z_im) <= 4)
	{
		o->temp = o->z_re * o->z_re - o->z_im * o->z_im + o->c_re;
		o->z_im = two * o->z_re * o->z_im + o->c_im;
		o->z_re = o->temp;
	}
	return (i);
}

int			ft_find_i_heart(t_gra *o, int two)
{
	int		i;

	i = -1;
	while (++i < o->max_iter && (o->z_re * o->z_re + o->z_im * o->z_im) <= 4)
	{
		o->temp = o->z_re * o->z_re - o->z_im * o->z_im + o->c_re;
		o->z_im = two * fabs(o->z_re) * o->z_im + o->c_im;
		o->z_re = o->temp;
	}
	return (i);
}

int			ft_find_i_celtic(t_gra *o, int two)
{
	int		i;

	i = -1;
	while (++i < o->max_iter && (o->z_re * o->z_re + o->z_im * o->z_im) <= 4)
	{
		o->temp = fabs(o->z_re * o->z_re - o->z_im * o->z_im) + o->c_re;
		o->z_im = two * o->z_re * o->z_im + o->c_im;
		o->z_re = o->temp;
	}
	return (i);
}

int			ft_find_i4(t_gra *o)
{
	int		i;

	i = -1;
	while (++i < o->max_iter && (o->z_re * o->z_re + o->z_im * o->z_im) <= 4)
	{
		o->temp = o->z_re * (o->z_re * o->z_re * o->z_re
			* o->z_re - 10 * o->z_re * o->z_re * o->z_im
			* o->z_im + 5 * o->z_im * o->z_im * o->z_im * o->z_im) + o->c_re;
		o->z_im = o->z_im * (5 * o->z_re * o->z_re
			* o->z_re * o->z_re - 10 * o->z_re * o->z_re * o->z_im
			* o->z_im + o->z_im * o->z_im * o->z_im * o->z_im) + o->c_im;
		o->z_re = o->temp;
	}
	return (i);
}
