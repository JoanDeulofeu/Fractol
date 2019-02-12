#include "fractol.h"

void	ft_viseur(t_s *s)
{
	int i;

	i = 0;
	while (i++ < 19)
		mlx_pixel_put (s->m_ptr, s->w_ptr, 490 + i, 500, BLACK);
	i = 0;
	while (i++ < 19)
		mlx_pixel_put (s->m_ptr, s->w_ptr, 500, 490 + i, BLACK);
}

void	ft_dply_menu(t_s *s)
{
	int color;

	if (s->color == 3 || s->color == 4 || s->color == 5)
		color = WHITE;
	else
		color = BLACK;
	if (s->affmenu == 0)
	{
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165, color,
			"Menu :");
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165 + (20), color,
			"M = Hide menu");
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165 + (20 * 2), color,
			"Arrow = Move");
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165 + (20 * 3), color,
			"+ or - = Iteration");
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165 + (20 * 4), color,
			"Scroll = Zoom");
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165 + (20 * 5), color,
			"Num [1-8] = Color");
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165 + (20 * 6), color,
			"L = Lock / Unlock");
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165 + (20 * 7), color,
			"D = Hide link");
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165 + (20 * 8), color,
			"V = Hide Scope");
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165 + (20 * 9), color,
			"Echap = Close");
	}
	else
		mlx_string_put(s->m_ptr, s->w_ptr, 15, 165, color,
			"M = Display menu");
	if (s->scope == 0)
		ft_viseur(s);
}
