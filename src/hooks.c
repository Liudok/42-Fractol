/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:10:05 by lberezyn          #+#    #+#             */
/*   Updated: 2018/01/05 15:10:09 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_gra		*key_hook_scale(t_gra *o, int keycode)
{
	double	temp1x;
	double	temp1y;
	double	temp2x;
	double	temp2y;

	temp1x = o->min_re + (WIN_W / 2) * (o->max_re - o->min_re) / WIN_W;
	temp1y = o->min_im + (WIN_H / 2) * (o->max_im - o->min_im) / WIN_H;
	temp2x = o->min_re;
	temp2y = o->min_im;
	if (keycode == 69)
	{
		o->min_re = temp1x - (o->max_re - o->min_re) / 4;
		o->max_re = temp1x + (o->max_re - temp2x) / 4;
		o->min_im = temp1y - (o->max_im - o->min_im) / 4;
		o->max_im = temp1y + (o->max_im - temp2y) / 4;
	}
	else if (keycode == 78)
	{
		o->min_re = temp1x - (o->max_re - o->min_re);
		o->max_re = temp1x + (o->max_re - temp2x);
		o->min_im = temp1y - (o->max_im - o->min_im);
		o->max_im = temp1y + (o->max_im - temp2y);
	}
	return (o);
}

t_gra		*key_hook_move(t_gra *o, int keycode)
{
	o->step = 100 * (o->max_re - o->min_re) / WIN_W;
	if (keycode == 124 && (o->min_re - o->step) > DBL_MIN)
	{
		o->min_re -= o->step;
		o->max_re -= o->step;
	}
	else if (keycode == 123 && (o->max_re - o->step) < DBL_MAX)
	{
		o->min_re += o->step;
		o->max_re += o->step;
	}
	if (keycode == 126 && (o->max_im - o->step) > DBL_MIN)
	{
		o->min_im -= o->step;
		o->max_im -= o->step;
	}
	else if (keycode == 125 && (o->min_im - o->step) < DBL_MAX)
	{
		o->min_im += o->step;
		o->max_im += o->step;
	}
	return (o);
}

t_gra		*key_hook_iterations(t_gra *o, int keycode)
{
	if (keycode == 24 && o->max_iter < 302)
		o->max_iter = o->max_iter + 2;
	else if (keycode == 27 && o->max_iter > 2)
		o->max_iter = o->max_iter - 2;
	return (o);
}

t_gra		*key_hook_def(t_gra *o)
{
	o->max_iter = 30.0;
	if (!ft_strcmp(o->fra_name, "mandelbrot")
		|| !ft_strcmp(o->fra_name, "tricorn")
		|| !ft_strcmp(o->fra_name, "four")
		|| !ft_strcmp(o->fra_name, "heart")
		|| !ft_strcmp(o->fra_name, "celtic")
		|| !ft_strcmp(o->fra_name, "other_celtic")
		|| !ft_strcmp(o->fra_name, "perpendicular"))
		*o = ft_def_mandel(o);
	else if (!ft_strcmp(o->fra_name, "julia"))
		*o = ft_def_julia(o);
	return (o);
}

int			key_hook(int keycode, t_gra *o)
{
	if (keycode == 53)
	{
		mlx_destroy_image(o->mlx, o->img);
		mlx_destroy_window(o->mlx, o->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 82)
		o = key_hook_def(o);
	else if (keycode == 78 || keycode == 69)
		o = key_hook_scale(o, keycode);
	else if (keycode >= 123 && keycode <= 126)
		o = key_hook_move(o, keycode);
	else if (keycode == 83 || keycode == 85)
		o = key_hook_color_modify(o, keycode);
	else if (keycode == 24 || keycode == 27)
		o = key_hook_iterations(o, keycode);
	else if (keycode == 67 || keycode == 75)
		o = key_hook_basecolor(o, keycode);
	mlx_clear_window(o->mlx, o->win);
	expose_hook(o);
	return (0);
}
