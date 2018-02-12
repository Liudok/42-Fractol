/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 17:39:22 by lberezyn          #+#    #+#             */
/*   Updated: 2018/01/02 17:39:27 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	check_quater_zoomup(t_gra *o, int x, int y)
{
	o->c_im = o->max_im - (double)y *
	(o->max_im - o->min_im) / WIN_H;
	o->c_re = o->min_re + (double)x *
	(o->max_re - o->min_re) / WIN_W;
	if (o->c_re < 0)
		o->max_re -= o->step;
	else if (o->c_re >= 0)
		o->min_re += o->step;
	if (o->c_im < 0)
		o->max_im -= o->step;
	else if (o->c_im >= 0)
		o->min_im += o->step;
}

void	check_quater_zoomback(t_gra *o, int x, int y)
{
	o->c_im = o->max_im - (double)y *
	(o->max_im - o->min_im) / WIN_H;
	o->c_re = o->min_re + (double)x *
	(o->max_re - o->min_re) / WIN_W;
	if (o->c_re < 0)
		o->max_re += o->step;
	else if (o->c_re >= 0)
		o->min_re -= o->step;
	if (o->c_im < 0)
		o->max_im += o->step;
	else if (o->c_im >= 0)
		o->min_im -= o->step;
}

int		ft_mouse_hook(int keycode, int x, int y, t_gra *o)
{
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H)
	{
		o->step = 100 * (o->max_re - o->min_re) / WIN_W;
		if (keycode == 4)
			check_quater_zoomup(o, x, y);
		else if (keycode == 5)
			check_quater_zoomback(o, x, y);
	}
	expose_hook(o);
	return (0);
}

int		ft_mouse_move(int x, int y, t_gra *o)
{
	if (o->lock)
	{
		o->c_im = o->max_im - (double)y *
		(o->max_im - o->min_im) / WIN_H;
		o->c_re = o->min_re + (double)x *
		(o->max_re - o->min_re) / WIN_W;
		expose_hook(o);
	}
	return (0);
}

t_gra	*key_hook_basecolor(t_gra *o, int keycode)
{
	if (keycode == 67 && o->color < 254)
		o->color++;
	else if (keycode == 75 && o->color > 0)
		o->color--;
	return (o);
}
