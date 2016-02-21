
typedef struct _lifegame_unit{
	int mark;
	int state;
}lifegame_unit;

typedef struct _lifegame{
	int width;
	int height;
	lifegame_unit** units;
}lifegame;


lifegame* open_lifegame();
void close_lifegame(lifegame* game);

void generate_lifegame(lifegame* game, int w, int h);

void random_lifegame(lifegame* game);
void next_generation(lifegame* game);
void dump_lifegame(lifegame* game);
