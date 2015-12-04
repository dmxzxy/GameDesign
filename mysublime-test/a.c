#include <stdio.h>
#include "array.h"


typedef struct effect{
	int type;
} EFFECT;

typedef struct buff{
	int starttime;
	int duration;

	int effect_row;
	int effect_col;
	EFFECT** effects;
} BUFF;

void init_buff(BUFF* bf, int row, int col){
	bf->starttime = 0;
	bf->duration = 0;
	bf->effect_row = row;
	bf->effect_col = col;
	bf->effects = (EFFECT**)malloc_array_2d(row, col, sizeof(EFFECT));
	int i = 0, j = 0;
	for(i = 0 ; i < bf->effect_row ; ++i){
		for(j = 0 ; j < bf->effect_col ; ++j){
			bf->effects[i][j].type = rand()%2;
		}
	}
}

void dump_buff(BUFF* bf){
	printf("starttime - %d\n", bf->starttime );
	printf("duration - %d\n", bf->duration );
	int i = 0, j = 0;
	for(i = 0 ; i < bf->effect_row ; ++i){
		for(j = 0 ; j < bf->effect_col ; ++j){
			printf("effects (%d,%d) - %d ", i, j, bf->effects[i][j].type );
		}
		printf("\n");
	}
}

int main(){
	BUFF* bf = (BUFF*)malloc(sizeof(BUFF));
	int point_size = sizeof(void*);
	int w = 5, h = 5;
	init_buff(bf, w, h);
	dump_buff(bf);
	free_array_2d((void**)bf->effects);

	system("pause");
	return 0;
}