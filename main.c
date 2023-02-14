/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:16:17 by arobu             #+#    #+#             */
/*   Updated: 2023/02/14 17:45:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define EATING_TIME 20000
#define THINKING_TIME 30000
#define SLEEPING_TIME 80000

pthread_t philosophers[NUM_PHILOSOPHERS];
pthread_mutex_t forks[NUM_PHILOSOPHERS];

void* philosopher(void* id) {
    int philosopher_id = *(int*) id;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking.\n", philosopher_id);
        usleep(THINKING_TIME);

        printf("Philosopher %d is hungry and wants to eat.\n", philosopher_id);

        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d picked up the left fork %d.\n", philosopher_id, left_fork);

        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d picked up the right fork %d.\n", philosopher_id, right_fork);

        printf("Philosopher %d is eating.\n", philosopher_id);
        usleep(EATING_TIME);

        printf("Philosopher %d finished eating and put down the forks.\n", philosopher_id);
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);

        printf("Philosopher %d is sleeping.\n", philosopher_id);
        usleep(SLEEPING_TIME);
    }
}

int main() {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        int* philosopher_id = malloc(sizeof(int));
        *philosopher_id = i;

        pthread_create(&philosophers[i], NULL, philosopher, philosopher_id);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}
