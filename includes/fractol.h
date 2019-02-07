#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include <string.h>
# include <stdio.h> //ATTENTION
# include <pthread.h> //ATTENTION
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
}					t_thr;

typedef struct		s_s
{
	void			*m_ptr;
	void			*w_ptr;
	void			*img;
	unsigned char	*s_img;
	int				itermax;
	int				move;
	int				fract;
	int				pxl;
	double			x;
	double			y;
	double			randx;
	double			randy;
	double			savex;
	double			savey;
	double			left;
	double			right;
	double			high;
	double			low;
	double			img_x;
	double			img_y;
	double			zoomx;
	double			zoomy;
	int				init;
}					t_s;

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
void				ft_fractales(t_s *s);
void				ft_zoom(t_s *s, int x, int y, int zoom);
int					ft_percent(int start, int end, int current);
int					ft_init_image(t_s *s, int sizex, int sizey);
void				ft_lightup_pixel(t_s *s, int x, int y, int color);
int					key_hook(int key, void *param);
int					mouse_hook(int key, int i, int j, void *param);
int					mouse_move(int x, int y, void *param);
int					ft_expose(void *param);
#endif
