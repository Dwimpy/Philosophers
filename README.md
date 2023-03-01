Dining Philosophers Problem Solution
====================================

This project presents a solution for the dining philosophers problem using threads and locks to prevent deadlocks and starvation.

Problem description
-------------------

The dining philosophers problem is a classic synchronization problem in computer science, where a number of philosophers sit at a round table and alternate between thinking and eating. The table has a number of forks, equal to the number of philosophers, and each philosopher needs two forks to eat. The problem is to find a way for the philosophers to share the forks without creating a deadlock, where all the philosophers are waiting for a fork that will never be released, or a starvation, where one or more philosophers are constantly waiting for a fork.

Solution description
--------------------

The solution implemented in this project uses threads to simulate the philosophers and locks to control the access to the forks. The simulation stops when all the philosophers have eaten a certain number of times or when a philosopher dies. The program takes the following arguments:

*   number\_of\_philosophers: the number of philosophers and also the number of forks.
*   time\_to\_die: if a philosopher didn't start eating time\_to\_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
*   time\_to\_eat: the time it takes for a philosopher to eat. During that time, they will need to hold two forks.
*   time\_to\_sleep: the time a philosopher will spend sleeping.
*   number\_of\_times\_each\_philosopher\_must\_eat (optional): if all philosophers have eaten at least number\_of\_times\_each\_philosopher\_must\_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

The program prints the following log for each state change of a philosopher:

*   timestamp\_in\_ms X has taken a fork
*   timestamp\_in\_ms X is eating
*   timestamp\_in\_ms X is sleeping
*   timestamp\_in\_ms X is thinking
*   timestamp\_in\_ms X died

Replace timestamp\_in\_ms with the current timestamp in milliseconds and X with the philosopher number.

Bonus part description
----------------------

In the bonus part, the solution is extended to use processes and semaphores to represent the forks. 
The program takes the same arguments as the mandatory part.
In this implementation, all the forks are placed in the middle of the table and represented by a semaphore 
that controls the access to them. Each philosopher is a separate process, and the main process is responsible 
for creating and managing them.

How to use it
-------------

1.  Clone the repository
2.  Open a terminal in the repository folder
3.  Go in the corresponding directory and use
```bash
  make
```
4.  Run `./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`

Example: `./philo 5 2000 1000 500 3`

This will simulate 5 philosophers with a time to die of 2 seconds, a time to eat of 1 second, a time to sleep of half a second, and each philosopher must eat 3 times. The program will print the log of each state change of the philosophers.
