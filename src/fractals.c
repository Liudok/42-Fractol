/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:16:27 by lberezyn          #+#    #+#             */
/*   Updated: 2017/12/29 16:16:33 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_gra		ft_def_julia(t_gra *o)
{
	o->min_re = -2.0;
	o->max_re = 2.0;
	o->min_im = -2.0;
	o->max_im = 2.0;
	o->freq = 0.1;
	o->color = 2;
	o->step = 10 * (o->max_re - o->min_re) / WIN_W;
	o->lock = 1;
	return (*o);
}

void		ft_mandel(t_gra *o)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		o->c_im = o->max_im - (double)y *
		(o->max_im - o->min_im) / WIN_H;
		while (++x < WIN_W)
		{
			o->c_re = o->min_re + (double)x *
			(o->max_re - o->min_re) / WIN_W;
			o->z_re = o->c_re;
			o->z_im = o->c_im;
			i = ft_find_i(o, 2);
			if (i < o->max_iter)
				put_pxl_in_img(o, x, y, get_pixel_color(o, i));
			else
				put_pxl_in_img(o, x, y, 0);
		}
	}
}

void		ft_perp(t_gra *o)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		o->c_im = o->max_im - (double)y *
		(o->max_im - o->min_im) / WIN_H;
		while (++x < WIN_W)
		{
			o->c_re = o->min_re + (double)x *
			(o->max_re - o->min_re) / WIN_W;
			o->z_re = (o->c_re);
			o->z_im = o->c_im;
			i = ft_find_i_heart(o, -2);
			if (i < o->max_iter)
				put_pxl_in_img(o, x, y, get_pixel_color(o, i));
			else
				put_pxl_in_img(o, x, y, 0);
		}
	}
}

void		ft_heart(t_gra *o)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		o->c_im = o->max_im - (double)y *
		(o->max_im - o->min_im) / WIN_H;
		while (++x < WIN_W)
		{
			o->c_re = o->min_re + (double)x *
			(o->max_re - o->min_re) / WIN_W;
			o->z_re = (o->c_re);
			o->z_im = o->c_im;
			i = ft_find_i_heart(o, 2);
			if (i < o->max_iter)
				put_pxl_in_img(o, x, y, get_pixel_color(o, i));
			else
				put_pxl_in_img(o, x, y, 0);
		}
	}
}
