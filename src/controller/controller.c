#include <ncurses.h>
#include "../core/core.h"
#include "controller.h"

static signed char r, c, mode;

static void render(void) {
    mvprintw(0, 0, "Score: %10u", score);
    for (char i = 0, *iter = grid; i < 20; ++i) {
        for (char j = 0; j < 20; ++j, ++iter) {
            mvaddch(i + 1, j << 1, *iter);
        }
    }
    mvprintw(21, 0, "%-10s", mode ? "Move" : " ");
    move(r + 1, c << 1);
}

void controller_init(void) {
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    core_init();
    mode = 0;
    render();
}

char controller_handle(void) {
    int ch = getch();
    switch (ch) {
    case 'q':
        return 0;
    case KEY_LEFT:
    case 'A':
    case 'a':
        if (mode) {
            core_move(r, c, LEFT);
            mode = 0;
        } else {
            c = (((c - 1) % 20) + 20) % 20;
        }
        break;
    case KEY_RIGHT:
    case 'D':
    case 'd':
        if (mode) {
            core_move(r, c, RIGHT);
            mode = 0;
        } else {
            c = (((c + 1) % 20) + 20) % 20;
        }
        break;
    case KEY_UP:
    case 'W':
    case 'w':
        if (mode) {
            core_move(r, c, UP);
            mode = 0;
        } else {
            r = (((r - 1) % 20) + 20) % 20;
        }
        break;
    case KEY_DOWN:
    case 'S':
    case 's':
        if (mode) {
            core_move(r, c, DOWN);
            mode = 0;
        } else {
            r = (((r + 1) % 20) + 20) % 20;
        }
        break;
    case 'Z':
    case 'z':
        mode = !mode;
        break;
    case 'R':
    case 'r':
        controller_init();
        return 1;
    }
    render();
    return 1;
}

void controller_finalize(void) {
    endwin();
}
