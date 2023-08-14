/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/14 10:14:53 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define WHITE_SPACE ' '
# define PATHNAME_START_INDEX 3
# define COLOR_START_INDEX 2
# define NORTH_TEXTURE	"NO"
# define SOUTH_TEXTURE	"SO"
# define WEST_TEXTURE	"WE"
# define EAST_TEXTURE	"EA"
# define FLOOR_COLOR	"F"
# define CEIL_COLOR		"C"

# define MAP_EXTENSION "cub"
# define TEXTURE_EXTENSION "xpm"

static void     game_loop(t_cub3d *cub3d);
int      exit_game(t_cub3d *cub3d);

// const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// };

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

t_bool map_has_wall_at(float x, float y)
{
	int map_index_x;
	int map_index_y;

	if ((x < 0 || x > WINDOW_WIDTH) || (y < 0 || y > WINDOW_HEIGHT))
		return (TRUE);
	map_index_x = floor(x / TILE_SIZE);
	map_index_y = floor(y / TILE_SIZE);
	return (map[map_index_y][map_index_x] != 0);
}

t_bool check_extension(const char *pathname, const char *extension)
{
	const char *file_ext;

	file_ext = ft_strrchr(pathname, '.');
	if (file_ext)
	{
		file_ext++;
		if (ft_strncmp(file_ext, extension, ft_strlen(extension) + 1) == 0)
			return (TRUE);
	}
	return (FALSE);
}

void    load_map(t_cub3d *cub3d, const char *pathname)
{
	int fd;

	if (!check_extension(pathname, MAP_EXTENSION))
		cub3d_error(NULL, MAP_EXTENSION_ERROR, MAP_EXTENSION_MSG);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		cub3d_error(NULL, MAP_FILE_ERROR, MAP_FILE_MSG);
	cub3d->map.tmp = read_map(fd);
}

void    parser_texture(t_cub3d *cub3d, t_texture *texture, char *expected)
{
	char   line[BUFFER];

	ft_strlcpy(line, *cub3d->map.tmp, BUFFER);
	if (line[0] != expected[0]
		|| line[1] != expected[1]
		|| line[2] != WHITE_SPACE)
		cub3d_error(cub3d, PARSER_TEXTURE_ERROR, PARSER_TEXTURE_MSG);
	else if (!check_extension(line, TEXTURE_EXTENSION))
		cub3d_error(cub3d, TEXTURE_EXTENSION_ERROR, TEXTURE_EXTENSION_MSG);
	texture->pathname = ft_substr(line, PATHNAME_START_INDEX, BUFFER);
	cub3d->map.tmp++;
}

int	extract_rgb(char *line)
{
    static int i = 0;
    static int calls = 0;
    int rgb;

	if (!*(line + i))
		return (-1);
	rgb = ft_atoi(line + i);
    while (line[i] && line[i] != ',')
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		i++;
	}
    if (line[i] == ',')
        i++;
    if (calls == 2)
        i = 0;
    calls++;
    return (rgb);
}

void	parser_color(t_cub3d *cub3d, t_rgb *color, char *expected)
{
	char line[BUFFER];

	ft_strlcpy(line, *cub3d->map.tmp, BUFFER);
	if (line[0] != expected[0] || line[1] != WHITE_SPACE)
		cub3d_error(cub3d, PARSER_COLOR_ERROR, PARSER_COLOR_MSG);
	color->r = extract_rgb(line + COLOR_START_INDEX);
	color->g = extract_rgb(line + COLOR_START_INDEX);
	color->b = extract_rgb(line + COLOR_START_INDEX);
	if (color->r == -1 || color->g == -1|| color->b == -1)
		cub3d_error(cub3d, PARSER_COLOR_ERROR, PARSER_COLOR_MSG);
	cub3d->map.tmp++;
}


void    parser_map(t_cub3d *cub3d)
{
	// char **tmp;

	// tmp = cub3d->map.tmp;
	parser_texture(cub3d, &cub3d->textures[NORTH], NORTH_TEXTURE);
	parser_texture(cub3d, &cub3d->textures[SOUTH], SOUTH_TEXTURE);
	parser_texture(cub3d, &cub3d->textures[WEST], WEST_TEXTURE);
	parser_texture(cub3d, &cub3d->textures[EAST], EAST_TEXTURE);
	parser_color(cub3d, &cub3d->color[FLOOR], FLOOR_COLOR);
	parser_color(cub3d, &cub3d->color[CEIL], CEIL_COLOR);

	for (int j = 0; cub3d->map.tmp[j]; j++)
	{
		printf("%s\n", cub3d->map.tmp[j]);
	}
	exit(1);
	
	//cub3d->textures[NORTH].path
	
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;


	cub3d.image.img_ptr = NULL;

	cub3d.ceil.r = -1;
	cub3d.ceil.g = -1;
	cub3d.ceil.b = -1;

	cub3d.floor.r = -1;
	cub3d.floor.g = -1;
	cub3d.floor.b = -1;
	
	cub3d.textures[WEST].img_ptr = NULL;
	cub3d.textures[EAST].img_ptr = NULL;
	cub3d.textures[NORTH].img_ptr = NULL;
	cub3d.textures[SOUTH].img_ptr = NULL;

	cub3d.textures[NORTH].pathname =  NULL;
	cub3d.textures[SOUTH].pathname =  NULL;
	cub3d.textures[WEST].pathname =  NULL;
	cub3d.textures[EAST].pathname =  NULL;
	
	
	if (argc != 2)
		cub3d_error(NULL, INVALID_ARGS_ERROR, INVALID_ARGS_MSG);
	load_map(&cub3d, argv[1]);

	//TODO: Separar TEXTURAS, CORES, MAPA.
	parser_map(&cub3d);

	// TODO: Válidar SE AS INF DOS MAPA ESTÃO CORRETAS.
	//check_map();

	// flood_fill(cub3d.map.map, 1, 3);
	// for (int i = 0; cub3d.map.map[i]; i++)
	// {
	//     for (int j = 0; cub3d.map.map[i][j]; j++)
	//     {
	//         if (cub3d.map.map[i][j] == '@')
	//             printf("%s%c%s", "\033[32m", cub3d.map.map[i][j], "\x1b[0;30m");
	//         else if (cub3d.map.map[i][j] == '!')
	//             printf("%s%c%s", "\033[31m", cub3d.map.map[i][j], "\x1b[0;30m");
	//         else
	//             printf("%s%c%s", "\033[31m", cub3d.map.map[i][j], "\x1b[0;30m");
	//     }
	//     printf("\n");
	// }
	//parser_map(&cub3d, argv[1]);
	//TODO: Fazer o parser do mapa.
	//parser_map()
	//load_texture(&cub3d);
	exit(1);

	// TODO: Verificar se informações do mapa são válidos: TEXTURAS, CORES, MAPA
	// check_map();
	

	//char **map_dup = generate_map("./dust.cub");
	//pegar a maior linha;
	//normalizar o mapa para todas linhas ser igual lenght da maior linha ou seja trocar espaços por 2

	// t_bool result = TRUE;
	
	// TODO: VERIFICAR SE O MAPA POSSUI CARACTER INVÁLIDOS QUE NÃO SEJA W,N,E,O,1,0
	//flood_fill(map_dup, 1, 3);
	// TODO: VARRER O MAPA MODIFICADO PELA FLOOD_FILL E PROCURAR CARACTER QUE SEJAM DIFERENTES DE 6,5,1


	// for (int i = 0; map_dup[i]; i++)
	// {
	//     for (int j = 0; map_dup[i][j]; j++)
	//     {
	//         if (map_dup[i][j] == '@')
	//             printf("%s%c%s", "\033[32m", map_dup[i][j], "\x1b[0;30m");
	//         else if (map_dup[i][j] == '!')
	//             printf("%s%c%s", "\033[31m", map_dup[i][j], "\x1b[0;30m");
	//         else
	//             printf("%s%c%s", "\033[31m", map_dup[i][j], "\x1b[0;30m");
	//     }
	//     printf("\n");
	// }


	// Player course.
	//cub3d.map.player_course = NORTH;

	// Flooor color.
	cub3d.floor.r = 0;
	cub3d.floor.g = 0;
	cub3d.floor.b = 0;

	// Ceil color.
	cub3d.ceil.r = 0;
	cub3d.ceil.g = 0;
	cub3d.ceil.b = 0;

	// // Texture path.
	// cub3d.ea_path = "./assets/textures/brick_blue.xpm";
	// cub3d.no_path = "./assets/textures/brick_green.xpm";
	// cub3d.so_path = "./assets/textures/brick_purple.xpm";
	// cub3d.we_path = "./assets/textures/brick_yellow.xpm";

	// // Texture ptr.
	// cub3d.textures[WEST].img_ptr = NULL;
	// cub3d.textures[EAST].img_ptr = NULL;
	// cub3d.textures[NORTH].img_ptr = NULL;
	// cub3d.textures[SOUTH].img_ptr = NULL;
	// cub3d.color_buffer = NULL;

	// cub3d.map.map = malloc(MAP_NUM_ROWS * sizeof(int **));
	// for (int i = 0; i < MAP_NUM_ROWS; i++)
	// {
	//     cub3d.map.map[i] = malloc(MAP_NUM_COLS * sizeof(int));
	//     for (int j = 0; j < MAP_NUM_COLS; j++)
	//         cub3d.map.map[i][j] = map[i][j];
	// }

	init_window(&cub3d);
	create_image(&cub3d);
	load_texture(&cub3d);
	player_setup(&cub3d);
	game_loop(&cub3d);
	return (0);
}

static void    game_loop(t_cub3d *cub3d)
{
	cub3d->color_buffer = malloc((WINDOW_WIDTH * WINDOW_HEIGHT) * sizeof(int));
	if (!cub3d->color_buffer)
		cub3d_error(cub3d, COLOR_BUFFER_MALLOC_ERROR, COLOR_BUFFER_MSG);
	mlx_hook(cub3d->window.mlx_win, KeyPress, KeyPressMask, &key_down, cub3d);
	mlx_hook(cub3d->window.mlx_win, KeyRelease, KeyReleaseMask, &key_up, cub3d);
	mlx_hook(cub3d->window.mlx_win, MotionNotify, PointerMotionMask, &mouse_move, cub3d);
	mlx_hook(cub3d->window.mlx_win, DestroyNotify, NoEventMask, &exit_game, cub3d);
	mlx_loop_hook(cub3d->window.mlx_ptr, render_game, cub3d);
	mlx_loop(cub3d->window.mlx_ptr);
}

int   exit_game(t_cub3d *cub3d)
{
	int i;

	i = -1;
	free(cub3d->color_buffer);
	while (++i < MAP_NUM_ROWS)
		free(cub3d->map.map[i]);
	free(cub3d->map.map);
	destroy_texture(&cub3d->window, cub3d->textures);
	destroy_image(&cub3d->window, &cub3d->image);
	destroy_window(&cub3d->window);
	exit(1);
	return (1);
}