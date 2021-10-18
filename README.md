## philosophers

project of 42 school where it is necessary to solve the problem of dining philosophers in C using a separate thread for each philosopher.

the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them. https://en.wikipedia.org/wiki/Dining_philosophers_problem

the goal is to create a program that simulate the 3 states of philosophers and print log of any change of status.

the project was made in accordance with the school design code standard in the C language.

### how to use
the project will work only on mas os.

last parameter is optional.
```
make
./philo num_of_ph time_to_die time_to_eat time_to_sleep [number_of_eat]
```
list of interesting cases
```
./philo 1 100 100 100   # should die
./philo 2 2 1 1         # should live
./philo 2 400 201 200   # should die
./philo 2 400 200 200   # should live
./philo 2 100 300 50    # should die
./philo 2 399 200 200   # should die
./philo 2 100 50 100    # should die
./philo 3 99 34 33      # should die
./philo 3 99 33 33      # should live
./philo 4 400 200 200   # should live
./philo 5 400 200 200   # should die
```
