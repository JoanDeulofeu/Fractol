#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include <string.h>
# include <stdio.h> //ATTENTION
# include <pthread.h>
# include <math.h>
# define XWIN 1040
# define YWIN 1040

typedef struct		s_thr
{
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	int				i;
	double			x;
	double			y;
	int				pxl;
	int				red;
	int				green;
	int				blue;
}					t_thr;

typedef struct		s_link
{
	void			*m_ptr;
	void			*w_ptr;
	void			*img;
	unsigned char	*s_img;
	int				itermax;
	int				move;
	double			movex;
	double			movey;
	int				color;
	int				fract;
	double			randx;
	double			randy;
	int				savex;
	int				savey;
	double			left;
	double			right;
	double			high;
	double			low;
	double			img_x;
	double			img_y;
	double			zoomx;
	double			zoomy;
	int				init;
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
	double			movex;
	double			movey;
	int				color;
	int				fract;
	double			randx;
	double			randy;
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
}					t_s;

void				ft_affiche_menu(t_s *s);
unsigned char		ft_red(t_s *s, t_thr *thr);
unsigned char		ft_green(t_s *s, t_thr *thr);
unsigned char		ft_blue(t_s *s, t_thr *thr);
void				ft_lightup_menu(t_s *s, t_thr *thr, unsigned char *s_img);
int					ft_do_link(t_s *s);
void				ft_fougere(t_s *s, t_thr *thr);
t_thr				*ft_calcul(t_s *s, t_thr *thr);
void				ft_resetmand(t_s *s, t_thr *thr);
void				ft_exit(int error);
void				*ft_thread_1(void *arg);
void				*ft_thread_2(void *arg);
void				*ft_thread_3(void *arg);
void				*ft_thread_4(void *arg);
void				*ft_thread_5(void *arg);
void				*ft_thread_6(void *arg);
void				*ft_thread_7(void *arg);
void				*ft_thread_8(void *arg);
int					ft_fractales(t_s *s);
void				ft_zoom(t_s *s, int x, int y, int zoom);
int					ft_percent(int start, int end, int current);
int					ft_init_image(void *ptr, int sizex, int sizey);
void				ft_lightup_pixel(t_s *s, t_thr *thr);
int					key_hook(int key, void *param);
int					mouse_hook(int key, int i, int j, void *param);
int					mouse_move(int x, int y, void *param);
int					ft_expose(void *param);
#endif
