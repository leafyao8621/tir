#ifndef _CORE_H_
#define _CORE_H_

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

extern char grid[400];
extern unsigned score;

void core_init(void);
void core_move(char r, char c, char dir);
void core_log(void);

#endif
