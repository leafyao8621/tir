#include "core/core.h"

int main(void) {
    core_init();
    core_log();
    core_move(1, 2, RIGHT);
    core_log();
    return 0;
}
