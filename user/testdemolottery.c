#include "types.h"
#include "stat.h"
#include "user.h"

#define RUNTIME 2000000000

int main(void) {
    int pipefd1[2], pipefd2[2];
    pipe(pipefd1);
    pipe(pipefd2);

    int c1 = fork();
    if (c1 == 0) {
        settickets(1);
        int start = uptime();
        volatile long i;
        for (i = 0; i < RUNTIME; i++);
        int end = uptime();
        int elapsed = end - start;
        write(pipefd1[1], &elapsed, sizeof(elapsed));
        exit();
    }

    int c2 = fork();
    if (c2 == 0) {
        settickets(9);
        int start = uptime();
        volatile long i;
        for (i = 0; i < RUNTIME; i++);
        int end = uptime();
        int elapsed = end - start;
        write(pipefd2[1], &elapsed, sizeof(elapsed));
        exit();
    }

    int r1, r2;
    read(pipefd1[0], &r1, sizeof(r1));
    read(pipefd2[0], &r2, sizeof(r2));

    wait();
    wait();

    printf(1, "Child 1 (1 ticket):  %d ticks\n", r1);
    printf(1, "Child 2 (9 tickets): %d ticks\n", r2);
  
    exit();
}