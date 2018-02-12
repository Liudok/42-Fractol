/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:23:48 by lberezyn          #+#    #+#             */
/*   Updated: 2017/12/22 12:23:53 by lberezyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <errno.h>

# define MES1 "error\n"
# define MES2 "Usage : ./fractol Mandelbrot, Julia, Tricorn, "
# define MES3 "Memory allocation failure\n"
# define MES4 "Initialization failure\n"
# define MES5 "Celtic, Celtic2, Four, Perpendicular or Heart\n"
# define WIN_W 800
# define WIN_H 800
# define DBL_MIN 2.2250738585072014E-308
# define DBL_MAX 1.7976931348623158E+308

typedef struct		s_gra
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*fra_name;
	char			*addr;
	char			*iter;
	int				bpp;
	int				sizeline;
	int				endian;
	double			freq;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			c_re;
	double			c_im;
	short			max_iter;
	double			z_re;
	double			z_im;
	double			temp;
	short			lock;
	int				color;
	double			step;
}					t_gra;

union				u_color
{
	unsigned int		color;
	unsigned char		channels[4];
};

int					ft_exit_x(void);
void				sponge(t_gra *o);
void				ft_draw(t_gra *o);
void				ft_error(char *s);
int					key_hook(int keycode, t_gra *o);
t_gra				*key_hook_default(t_gra *o);
t_gra				*key_hook_move(t_gra *o, int keycode);
t_gra				*key_hook_scale(t_gra *o, int keycode);
t_gra				*key_hook_color_modify(t_gra *o, int keycode);
t_gra				*key_hook_iterations(t_gra *o, int keycode);
t_gra				*key_hook_basecolor(t_gra *o, int keycode);
t_gra				*key_hook_def(t_gra *o);
int					ft_mouse_move(int x, int y, t_gra *o);
void				check_quater_zoomup(t_gra *o, int x, int y);
void				check_quater_zoomback(t_gra *o, int x, int y);
int					expose_hook(t_gra *o);
void				ft_mandel(t_gra *o);
t_gra				ft_def_mandel(t_gra *o);
void				ft_julia(t_gra *o);
t_gra				ft_def_julia(t_gra *o);
void				ft_tricorn(t_gra *o);
void				ft_celtic(t_gra *o);
void				ft_other_celtic(t_gra *o);
void				ft_heart(t_gra *o);
void				ft_perp(t_gra *o);
void				ft_four(t_gra *o);
int					ft_find_i_celtic(t_gra *o, int two);
int					ft_find_i_heart(t_gra *o, int two);
int					ft_find_i(t_gra *o, int two);
int					ft_find_i4(t_gra *o);
int					ft_mouse_hook(int keycode, int x, int y, t_gra *o);
int					get_pixel_color(t_gra *o, int iterations);
void				put_pxl_in_img(t_gra *o, int x, int y, int color);

#endif
