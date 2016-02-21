#include "lifegame.h"
#include <windows.h>
#include "array.h"

int main(){
	lifegame* game = open_lifegame();
	generate_lifegame(game, 5, 5);
	random_lifegame(game);
	dump_lifegame(game);

	int runstate = 1;
	while(runstate == 1){
		Sleep(250);
		system("cls");
		next_generation(game);
		dump_lifegame(game);
	}
	close_lifegame(game);
}