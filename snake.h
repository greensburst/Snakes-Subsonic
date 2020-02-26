#define WIDTH 60
#define HEIGHT 20

typedef struct {
	int x;
	int y;
} FOOD;

typedef struct {
	int x;
	int y;
} SNAKE_BODY;

typedef struct {
	int size;
	SNAKE_BODY body[WIDTH*HEIGHT];
} SNAKE;

extern void init_food();
extern void init_snake();
extern void init_wall();
extern void show();
extern void play();
