
#include "miniRT.h"

int	ft_init_mlx(t_map_data *mlx)
{
	mlx->pic = mlx_init();
	if (!mlx->pic)
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	if (!mlx->win_ptr)
		return (0);
	mlx_hook(mlx->win_ptr, 17, 0, crossclose, (void *)mlx);
	mlx_hook(mlx->win_ptr, 02, 1L << 0, esc_key, (void *)mlx);
	return (1);
}

int	ft_init_image(t_data *img, t_map_data *mlx)
{
	img->img = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_p),
			&(img->line_len), &(img->endian));
	if (!img->addr)
		return (0);
	mlx->image = img;
	return (1);
}