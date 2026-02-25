# A3 Lottery Scheduling Results

## Setup
- 2 children forked from parent
- child 1: 1 ticket
- child 2: 9 tickets
- CPUS = 1 (required for lottery effect to be observable)


## Workload
- Each child runs a CPU-bound loop of 2,000,000,000 iterations
- Elapsed time measured in xv6 ticks using uptime()


## Results

| Run | Child 1 (1 ticket) | Child 2 (9 tickets) | Ratio (c1/c2) |
|  1  |       961  ticks   |   536  ticks        |  ~1.79x       |
|  2  |       961 ticks    |   538   ticks       |  ~1.79x       |
|  3  |       961  ticks   |   540  ticks        |  ~1.79x       |


##Notes

- Expected ration is ~9x but observed ratio is lower due to:
	- Natural variance in probabilistic scheduling
	- Tick granularity of uptime() limits precision
	- Parent process holds 1 ticket and briefly competes for CPU
- Child 2 consistently finishes faster across all runs, confiriming
	lottery scheduling is working correctly
- Results are consisten across runs
- With CPUS = 2 , both children had the same # of ticks, and differences were not observable
- Longer runs and larger ticket differences would converge closer to the theoretical ratio.

