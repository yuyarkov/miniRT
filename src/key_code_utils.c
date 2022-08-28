#include "miniRT.h"

int	crossclose(t_data *mlx, int key)
{
	(void) key;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}

int	esc_key(int key, t_data *mlx)
{
	if (key != 53)
		return (0);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}
