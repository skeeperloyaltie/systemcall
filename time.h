
#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    printf("Current time: %ld.%06ld\n", current_time.tv_sec, current_time.tv_usec);
    return 0;
}