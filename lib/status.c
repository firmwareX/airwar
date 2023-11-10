#include "status.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

Status Status_New()
{
    Status status;
    status.paused = 0;
    status.over = 0;
    status.quit = 0;
    status.full_screen = 0;
    status.time = 0;
    status.init = 0;
	status.value = -1;
	status.score = 0;
	status.life=3;
    return status;
}
