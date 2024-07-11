# Philosophers

## Description
The Philosophers project simulates the classic dining philosophers problem using threads and mutexes. The goal is to manage the synchronization and lifecycle of multiple philosopher threads that compete for shared resources (forks) to eat and think.

## Files

- **Makefile**: Makefile for compiling the Philosophers project.
- **check.c**: Utility functions for checking the state of philosophers.
- **ft_time.c**: Utility functions for time management.
- **main.c**: Main entry point for starting the simulation.
- **one_philo.c**: Functions for managing the lifecycle of a single philosopher.
- **philo.h**: Header file containing function prototypes and constants.
- **simulation.c**: Functions for running and managing the simulation.

## Compilation

To compile the Philosophers project, navigate to the root directory and run:
```sh
make
```

This will compile the executable philo.

## Usage
## Running Philosophers
To start the Philosophers simulation, run the following command:

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Parameters
- **number_of_philosophers**: Number of philosophers (threads) in the simulation.
- **time_to_die**: Time in milliseconds after which a philosopher dies if they haven't eaten.
- **time_to_eat**: Time in milliseconds it takes for a philosopher to eat.
- **time_to_sleep**: Time in milliseconds a philosopher spends sleeping after eating or thinking.
- **[number_of_times_each_philosopher_must_eat]** (optional): Number of times each philosopher must eat before the simulation ends.

### Example
```sh
./philo 5 800 200 200
```
This will simulate 5 philosophers with a time-to-die of 800ms, time-to-eat of 200ms, and time-to-sleep of 200ms.

## Contributors
[pschemit](https://github.com/Monkey42Github)

