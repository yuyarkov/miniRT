#include "../includes/miniRT.h"

t_ray	ray_create(t_vec3 origin, t_vec3 direction)
{
	t_ray	result;

	result.origin = origin;
	result.direction = direction;
	return (result);
}

t_vec3	ray_get_direction(int x, int y, t_camera *camera)
{
	double	fov_coeff;
	double	aspect_ratio;
	double	p_x;
	double	p_y;
	t_vec3	dir;

    //printf("inside get_direction, camera: %p\n", camera);
	fov_coeff = tan(camera->fov / 2 * M_PI / 180);
	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	p_x = (2 * (x + 0.5) / (double)WINDOW_WIDTH - 1) * aspect_ratio * fov_coeff;
	p_y = (1 - 2 * (y + 0.5) / (double)WINDOW_HEIGHT) * fov_coeff;
	dir = vec3_create(p_x, p_y, -1);
	vector_normalize(&dir);
	return (dir);
}

t_ray	ray_from_camera(int x, int y, t_camera *camera)
{
	t_matrix	view;
	t_vec3		origin;
	t_vec3		direction;

    // printf("inside ray_from_camera, camera: %p\n", camera);
    // print_vector(camera->position, "camera->position");
    // print_vector(camera->orientation, "camera->orientation");
	view = look_at(camera->position, camera->orientation);
	origin = multiply_by_matrix(vec3_create(0, 0, 0), view);
//printf("before get_direction, x: %d, y: %d, camera: %p\n", x, y, camera);
	direction = ray_get_direction(x, y, camera);
	direction = multiply_by_matrix(direction, view);
	direction = vector_minus(direction, origin);
	vector_normalize(&direction);
	return (ray_create(origin, direction));
}