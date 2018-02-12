/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 17:29:56 by lberezyn          #+#    #+#             */
/*   Updated: 2018/01/02 17:29:59 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		ft_julia(t_gra *o)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			o->z_re = o->min_re + (double)x *
			(o->max_re - o->min_re) / WIN_W;
			o->z_im = o->max_im - (double)y *
			(o->max_im - o->min_im) / WIN_H;
			i = ft_find_i(o, 2);
			if (i < o->max_iter)
				put_pxl_in_img(o, x, y, get_pixel_color(o, i));
			else
				put_pxl_in_img(o, x, y, 0);
		}
	}
}

void		ft_tricorn(t_gra *o)
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
			i = ft_find_i(o, -2);
			if (i < o->max_iter)
				put_pxl_in_img(o, x, y, get_pixel_color(o, i));
			else
				put_pxl_in_img(o, x, y, 0);
		}
	}
}

void		ft_celtic(t_gra *o)
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
			i = ft_find_i_celtic(o, 2);
			if (i < o->max_iter)
				put_pxl_in_img(o, x, y, get_pixel_color(o, i));
			else
				put_pxl_in_img(o, x, y, 0);
		}
	}
}

void		ft_other_celtic(t_gra *o)
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
			i = ft_find_i_celtic(o, -2);
			if (i < o->max_iter)
				put_pxl_in_img(o, x, y, get_pixel_color(o, i));
			else
				put_pxl_in_img(o, x, y, 0);
		}
	}
}

void		ft_four(t_gra *o)
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
			i = ft_find_i4(o);
			if (i < o->max_iter)
				put_pxl_in_img(o, x, y, get_pixel_color(o, i));
			else
				put_pxl_in_img(o, x, y, 0);
		}
	}
}
