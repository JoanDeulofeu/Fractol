/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:25:04 by jgehin            #+#    #+#             */
/*   Updated: 2019/02/13 15:38:35 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <math.h>
# define XWIN 1040
# define YWIN 1040
# define BLACK 0x3A3A3A
# define WHITE 0xF6F6F6

typedef struct		s_thr
{
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	int				fzr;
	int				fzi;
	int				i;
	double			x;
	double			y;
	int				pxl;
}					t_thr;

typedef struct		s_link
{
	void			*img;
	unsigned char	*s_img;
}					t_link;

typedef struct		s_s
{
	void			*m_ptr;
	void			*w_ptr;
	void			*img;
	unsigned char	*s_img;
	int				dolink;
	t_link			*link1;
	t_link			*link2;
	t_link			*link3;
	t_link			*link4;
	int				itermax;
	int				move;
	int				afflink;
	int				affmenu;
	double			movex;
	double			movey;
	double			zoom_coef;
	double			diffx;
	double			diffy;
	int				color;
	int				julia;
	int				fract;
	int				savefract;
	int				savex;
	int				savey;
	double			left;
	double			right;
	double			high;
	double			low;
	int				img_x;
	int				img_y;
	double			zoomx;
	double			zoomy;
	int				init;
	int				scope;
}					t_s;

void				ft_init_mand(t_s *s);
void				ft_init_julia(t_s *s, int julia);
void				ft_init_joan(t_s *s);
void				ft_dply_menu(t_s *s);
void				ft_affiche_link(t_s *s);
unsigned char		ft_red(t_s *s, t_thr *thr);
unsigned char		ft_green(t_s *s, t_thr *thr);
unsigned char		ft_blue(t_s *s, t_thr *thr);
void				ft_lightup_menu(t_s *s, t_thr *thr, unsigned char *s_img);
int					ft_init_image_menu(t_s *s, void *ptr, int sizex, int sizey);
int					ft_do_link(t_s *s);
void				ft_init_frac(t_s *s);
void				ft_fougere(t_s *s, t_thr *thr);
t_thr				*ft_calcul(t_s *s, t_thr *thr);
void				ft_resetmand(t_s *s, t_thr *thr);
void				ft_exit(int error, t_s *s);
void				*ft_thread_1(void *arg);
void				*ft_thread_2(void *arg);
void				*ft_thread_3(void *arg);
void				*ft_thread_4(void *arg);
void				*ft_thread_5(void *arg);
void				*ft_thread_6(void *arg);
void				*ft_thread_7(void *arg);
void				*ft_thread_8(void *arg);
int					ft_fractales(t_s *s, int i);
void				ft_zoom(t_s *s, int x, int y, int zoom);
int					ft_percent(int start, int end, int current);
int					ft_init_image(void *ptr, int sizex, int sizey);
void				ft_lightup_pixel(t_s *s, t_thr *thr);
int					key_hook(int key, void *param);
int					mouse_hook(int key, int i, int j, void *param);
int					mouse_move(int x, int y, void *param);
int					ft_expose(void *param);
#endif
