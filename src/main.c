/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:13:10 by lberezyn          #+#    #+#             */
/*   Updated: 2017/12/29 16:13:16 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_gra		ft_def_mandel(t_gra *o)
{
	o->min_re = -2.0;
	o->max_re = 1.0;
	o->min_im = -1.2;
	o->max_im = o->min_im + (o->max_re - o->min_re) * WIN_H / WIN_W;
	o->freq = 0.1;
	o->color = 2;
	o->step = 100 * (o->max_re - o->min_re) / WIN_W;
	o->lock = 0;
	return (*o);
}

int			ft_get_name(char *s, t_gra *o)
{
	if (ft_strcmp(s, "Julia") == 0 || ft_strcmp(s, "julia") == 0)
	{
		o->fra_name = "julia";
		*o = ft_def_julia(o);
		return (1);
	}
	else if (ft_strcmp(s, "Mandelbrot") == 0 || ft_strcmp(s, "mandelbrot") == 0)
		o->fra_name = "mandelbrot";
	else if (ft_strcmp(s, "Tricorn") == 0 || ft_strcmp(s, "tricorn") == 0)
		o->fra_name = "tricorn";
	else if (ft_strcmp(s, "Four") == 0 || ft_strcmp(s, "four") == 0)
		o->fra_name = "four";
	else if (ft_strcmp(s, "Celtic") == 0 || ft_strcmp(s, "celtic") == 0)
		o->fra_name = "celtic";
	else if (ft_strcmp(s, "Celtic2") == 0 || ft_strcmp(s, "celtic2") == 0)
		o->fra_name = "other_celtic";
	else if (ft_strcmp(s, "Heart") == 0 || ft_strcmp(s, "heart") == 0)
		o->fra_name = "heart";
	else if (ft_strcmp(s, "Perpendicular") == 0 ||
		ft_strcmp(s, "perpendicular") == 0)
		o->fra_name = "perpendicular";
	else
		return (0);
	*o = ft_def_mandel(o);
	return (1);
}

int			main(int ac, char **av)
{
	t_gra	o;

	if (ac != 2 || !(ft_get_name(av[1], &o)))
	{
		ft_putstr(MES2);
		ft_error(MES5);
	}
	if (!(o.mlx = mlx_init()))
		ft_error(MES4);
	if (!(o.win = mlx_new_window(o.mlx, WIN_W, WIN_H, o.fra_name)))
		ft_error(strerror(errno));
	o.max_iter = 30.0;
	o.addr = NULL;
	mlx_expose_hook(o.win, expose_hook, &o);
	mlx_hook(o.win, 4, 5, ft_mouse_hook, &o);
	mlx_hook(o.win, 6, 1L << 6, ft_mouse_move, &o);
	mlx_hook(o.win, 2, 0, key_hook, &o);
	mlx_hook(o.win, 17, 1L << 17, ft_exit_x, 0);
	mlx_loop(o.mlx);
	return (0);
}

void		ft_error(char *s)
{
	ft_putstr(s);
	exit(0);
}

int			ft_exit_x(void)
{
	exit(1);
}
