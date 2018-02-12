/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:37:16 by lberezyn          #+#    #+#             */
/*   Updated: 2017/12/26 18:37:26 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int					expose_hook(t_gra *o)
{
	if (!o->addr)
	{
		if (!(o->img = mlx_new_image(o->mlx, WIN_W + 300, WIN_H)))
			ft_error(strerror(errno));
		if (!(o->addr = mlx_get_data_addr(o->img, &o->bpp,
			&o->sizeline, &o->endian)))
			ft_putendl_fd(strerror(errno), 2);
	}
	ft_draw(o);
	mlx_string_put(o->mlx, o->win, 40, 40, 0x2DFFFF, "CONTROL KEYS:");
	mlx_string_put(o->mlx, o->win, 40, 80, 0xFFFFFF, "MOVE = < > ^ v");
	mlx_string_put(o->mlx, o->win, 40, 100, 0xFFFFFF, "ZOOM = + or - on num");
	mlx_string_put(o->mlx, o->win, 40, 120, 0xFFFFFF, "COLORS = 1 or 3");
	mlx_string_put(o->mlx, o->win, 40, 140, 0xFFFFFF, "RESET = 0");
	mlx_string_put(o->mlx, o->win, 40, 160, 0xFFFFFF, "EXIT = ESC");
	mlx_string_put(o->mlx, o->win, 40, 180, 0xFFFFFF, "ZOOM = mouse scroll");
	mlx_string_put(o->mlx, o->win, 40, 200, 0xFFFFFF, "ITERATIONS = + or -");
	mlx_string_put(o->mlx, o->win, 40, 220, 0xFFFFFF, "BASE COLOR = * or /");
	mlx_string_put(o->mlx, o->win, 40, 740, 0xFFFFFF, "ITERATIONS:");
	o->iter = ft_itoa(o->max_iter);
	mlx_string_put(o->mlx, o->win, 40, 760, 0xFFFFFF, o->iter);
	free(o->iter);
	if (o->max_iter >= 300)
		mlx_string_put(o->mlx, o->win, 80, 760, 0xFFFFFF, "No more");
	return (0);
}

int					get_pixel_color(t_gra *o, int iterations)
{
	union u_color	c;
	double			continuous_index;

	continuous_index = (iterations + 1 - (log((log(sqrt(o->z_re *
		o->z_re + o->z_im * o->z_im)) / 2) / log(2)) / log(2))) * o->freq;
	c.channels[0] = cos(continuous_index) * 127 + 128;
	c.channels[1] = cos(continuous_index + o->color) * 127 + 128;
	c.channels[2] = cos(continuous_index + 2 * o->color) * 127 + 128;
	c.channels[3] = 0;
	return (c.color);
}

void				put_pxl_in_img(t_gra *o, int x, int y, int color)
{
	int				i;
	unsigned int	pixel;

	i = -1;
	pixel = y * (o->sizeline) + x * (o->bpp / 8);
	while (++i < (o->bpp / 8))
	{
		o->addr[pixel + i] = color;
		color /= 256;
	}
}

void				ft_draw(t_gra *o)
{
	if (!ft_strcmp(o->fra_name, "mandelbrot"))
		ft_mandel(o);
	else if (!ft_strcmp(o->fra_name, "julia"))
		ft_julia(o);
	else if (!ft_strcmp(o->fra_name, "four"))
		ft_four(o);
	else if (!ft_strcmp(o->fra_name, "tricorn"))
		ft_tricorn(o);
	else if (!ft_strcmp(o->fra_name, "heart"))
		ft_heart(o);
	else if (!ft_strcmp(o->fra_name, "celtic"))
		ft_celtic(o);
	else if (!ft_strcmp(o->fra_name, "other_celtic"))
		ft_other_celtic(o);
	else if (!ft_strcmp(o->fra_name, "perpendicular"))
		ft_perp(o);
	mlx_put_image_to_window(o->mlx, o->win, o->img, 0, 0);
}

t_gra				*key_hook_color_modify(t_gra *o, int keycode)
{
	if (keycode == 83 && o->freq < 200)
		o->freq = o->freq + 0.01;
	else if (keycode == 85 && o->freq > 0.1)
		o->freq = o->freq - 0.01;
	return (o);
}
