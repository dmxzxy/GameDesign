#pragma once

#include <malloc.h>

static void** malloc_array_2d(int row, int col, int stsize){
	int point_size = sizeof(void*);
	void** arr = (void**)malloc(point_size*row + stsize * row * col);
	if(arr != NULL){
		void* chead = (void*)((int)arr + point_size*row);
		while(row--)
			arr[row] = (void*)((int)chead + row * col * stsize);
	}
	return arr;
}

static void free_array_2d( void** arr ){
	if(arr != NULL)
		free(arr);
}
