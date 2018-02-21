#include <signal.h>  // signal
#include <stdio.h>   // printf
#include <stdlib.h>  // atoi
#include <time.h>    // nanosleep
#include <unistd.h>  // ualarm

struct timespec sleep_ts = {};
size_t work_us = 0;

void snooze(int _)
{
    nanosleep(&sleep_ts, NULL);
    ualarm(work_us, 0);
}

int main(int argc, char **argv)
{
    size_t x = 0;
    size_t work_px, sleep_px;
    const size_t s_frac = 10;  // this many work/sleep cycles per second

    if (argc != 2 || (work_px = atoi(argv[1])) <= 0 || work_px > 100) {
        printf("usage: %s CPU_PERCENT\n", argv[0]);
        return 0;
    }
    sleep_px = 100 - work_px;
    work_us = 1000000 / 100 / s_frac * work_px;               // work in usec
    sleep_ts.tv_nsec = 1000000000 / 100 / s_frac * sleep_px;  // sleep in nsec

    signal(SIGALRM, snooze);  // BSD semantics on Linux, per signal(2)
    ualarm(work_us, 0);

    for (;; x++) ;

    return 0;
}

