# my_fdf

My fdf logic how to draw a line

FdF is  interesting 3D grapics project. It is helpful to divide this big pie into small pieces.

~ step 1: main (and project) structure
    - check ./fdf usage: ac == 2
    - open map  
    - create map  
    - get map;
    - draw map;


~ step 2: parse & store
    - fn: open, get_map, get_xy, get_z
    - parse the data and check if you have a valid map.
    - you can make the checks during parsing: 
            - usage: ac == 2
            - reading: open > 0
            - valid map: same width in every line
            - create map: memory err
            

    - go with get_next_line line by line, get the width and the height of the map, check if the number of points in every line is the same (valid map), store x & y coords, store z coords and color. 
    - get and store max & min z values, to create the color range in the future.

~ step 3: draw map
    - 


Memory leaks fixing

- create map
    map = (t_map *)ft_memalloc(sizeof(t_map))

- get_z
    
    split = NULL;
	line = NULL;
    map->map_z = ft_memalloc(sizeof(t_point *) * map->height);
	while (++i < map->height)
	{
		map->map_z[i] = ft_memalloc(sizeof(t_point) * map->width);
	}

- get_z1

    while (--i >= 0)
			free(split[i]);
		free(split);
		free(line);

- get_z2
    if (ft_strchr(split[i], ',') != NULL)
	{
		tmp = ft_strsplit(split[i], ',');
		map->map_z[h][i].z = ft_atoi(tmp[0]);
		map->map_z_prj[h][i] = ft_atoi(tmp[0]);
		map->map_z[h][i].color = ft_atoi_base(tmp[1] + 2, 16);
		free(tmp[0]);
		free(tmp[1]);
	}

- get_extra
    map->map_z_adj = ft_memalloc(sizeof(double *) * map->height);
	map->map_z_new = ft_memalloc(sizeof(double *) * map->height);
	map->map_z_prj = ft_memalloc(sizeof(double *) * map->height);
	while (++i < map->height)
	{
		map->map_z_adj[i] = ft_memalloc(sizeof(double) * map->width);
		map->map_z_new[i] = ft_memalloc(sizeof(double) * map->width);
		map->map_z_prj[i] = ft_memalloc(sizeof(double) * map->width);
	}




    src git:(master) ✗ grep "malloc" *.c
main.c: if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
parse.c:        map->map_z = ft_memalloc(sizeof(t_point *) * map->height);
parse.c:                map->map_z[i] = ft_memalloc(sizeof(t_point) * map->width);
parse2.c:       map->map_z_adj = ft_memalloc(sizeof(double *) * map->height);
parse2.c:       map->map_z_new = ft_memalloc(sizeof(double *) * map->height);
parse2.c:               map->map_z_adj[i] = ft_memalloc(sizeof(double) * map->width);
parse2.c:               map->map_z_new[i] = ft_memalloc(sizeof(double) * map->width);
➜  src git:(master) ✗ grep "free" *.c  
hooks.c:                free(map);
parse.c:                        free(split[i]);
parse.c:                free(split);
parse.c:                free(line);
parse2.c:               free(tmp[0]);
parse2.c:               free(tmp[1]);