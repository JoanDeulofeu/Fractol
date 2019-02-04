#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include <string.h>
# include <stdio.h> //ATTENTION
# include <math.h>
# define XWIN 2000
# define YWIN 1000

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				alpha;
}					t_rgb;

typedef struct		s_s
{
	void			*m_ptr;
	void			*w_ptr;
	void			*img;
	unsigned char	*s_img;
	int				itermax;
	float			zr;
	float			zi;
	int				i;
	int				fract;
	int				pxl;
	float			x;
	float			y;
	float			tmp;
	float			cr;
	float			ci;
	float			left;
	float			right;
	float			high;
	float			low;
	float			img_x;
	float			img_y;
	float			zoomx;
	float			zoomy;
	int				init;
}					t_s;

void				ft_fractales(t_s *s);
void				ft_zoom(t_s *s, int x, int y, int zoom);
int					ft_percent(int start, int end, int current);
int					ft_init_image(t_s *s, int sizex, int sizey);
void				ft_lightup_pixel(t_s *s, int x, int y, int color);
int					key_hook(int key, void *param);
int					mouse_hook(int key, int i, int j, void *param);
int					ft_expose(void *param);
#endif
