#include <stdio.h>
#include "lifegame.h"
#include "array.h"


lifegame* open_lifegame(){
	lifegame* game = (lifegame*)malloc(sizeof(lifegame));
	return game;
}

void close_lifegame(lifegame* game){
	if(game != NULL){
		free_array_2d((void**)game->units);
		free(game);
	}
}

void generate_lifegame(lifegame* game, int w, int h){
	game->width = w;
	game->height = h;
	game->units = (lifegame_unit**)malloc_array_2d(w, h, sizeof(lifegame_unit));
	int w_walk = 0;
	int h_walk = 0;
	for(w_walk = 0 ; w_walk < w ; ++w_walk){
		for(h_walk = 0 ; h_walk < h ; ++h_walk){
			game->units[w_walk][h_walk].state = 0;
			game->units[w_walk][h_walk].mark = 0;
		}
	}
}

void v(lifegame* game){
	int w_walk = 0;
	int h_walk = 0;
	for(w_walk = 0 ; w_walk < game->width ; ++w_walk){
		for(h_walk = 0 ; h_walk < game->height ; ++h_walk){
			game->units[w_walk][h_walk].state = game->units[w_walk][h_walk].mark;
		}
	}
}

void random_lifegame(lifegame* game){
	int w_walk = 0;
	int h_walk = 0;
	for(w_walk = 0 ; w_walk < game->width ; ++w_walk){
		for(h_walk = 0 ; h_walk < game->height ; ++h_walk){
			game->units[w_walk][h_walk].mark = rand()%2;
		}
	}
	v(game);
}

int is_live_unit(lifegame* game, int x, int y){
	if( x >= 0 && x < game->width ){
		if( y >= 0 && y < game->height ){
			if(game->units[x][y].state > 0){
				return 1;
			}
		}
	}

	return 0;
}

int count_neighbour(lifegame* game, int x, int y){
	int count = 0;
	count += is_live_unit(game, x-1, y);
	count += is_live_unit(game, x+1, y);
	count += is_live_unit(game, x, y-1);
	count += is_live_unit(game, x, y+1);
	count += is_live_unit(game, x-1, y-1);
	count += is_live_unit(game, x+1, y-1);
	count += is_live_unit(game, x-1, y+1);
	count += is_live_unit(game, x+1, y+1);
	return count;
}

void scan_unit(lifegame* game){
	int w_walk = 0;
	int h_walk = 0;
	for(w_walk = 0 ; w_walk < game->width ; ++w_walk){
		for(h_walk = 0 ; h_walk < game->height ; ++h_walk){
			int neighbour = 0;
			neighbour = count_neighbour(game, w_walk, h_walk);
			if(neighbour == 3 || neighbour == 2){
				game->units[w_walk][h_walk].mark = 1;
			}else{
				game->units[w_walk][h_walk].mark = 0;
			}
		}
	}
}

void next_generation(lifegame* game){
	scan_unit(game);
	v(game);
}

void dump_lifegame(lifegame* game){
	int w_walk = 0;
	int h_walk = 0;
	for(w_walk = 0 ; w_walk < game->width ; ++w_walk){
		for(h_walk = 0 ; h_walk < game->height ; ++h_walk){
			printf("%d ", game->units[w_walk][h_walk].state);
		}
		printf("\n");
	}
}
