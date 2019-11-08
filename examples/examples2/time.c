#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <string.h>

#define DURATION(start, end) ((end.tv_usec - start.tv_usec) + \
                              (end.tv_sec - start.tv_sec) * 1000000)

int main()
{
    struct itimerval initial, update;
    initial.it_value.tv_sec = 20;
    initial.it_interval.tv_sec = 1;
    memcpy(&(initial.it_interval), &(initial.it_value), sizeof(initial.it_value));

    setitimer(ITIMER_REAL, &initial, NULL);
    while (1)
    {
        getitimer(ITIMER_REAL, &update);
    }
}