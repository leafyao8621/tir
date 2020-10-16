#include "controller/controller.h"

int main(void) {
    controller_init();
    for (; controller_handle(););
    controller_finalize();
    return 0;
}
