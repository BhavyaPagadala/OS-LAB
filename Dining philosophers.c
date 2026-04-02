#include <stdio.h>

#define N 5

int state[N]; // 0 = thinking, 1 = hungry, 2 = eating

// Function to check if philosopher can eat
void test(int i) {
    if(state[i] == 1 &&
       state[(i + 4) % N] != 2 &&
       state[(i + 1) % N] != 2) {

        state[i] = 2;
        printf("Philosopher %d is Eating\n", i);
    }
}

// Take forks
void take_forks(int i) {
    state[i] = 1;
    printf("Philosopher %d is Hungry\n", i);

    test(i);
}

// Put forks
void put_forks(int i) {
    state[i] = 0;
    printf("Philosopher %d is Thinking\n", i);

    test((i + 4) % N);
    test((i + 1) % N);
}

int main() {
    int i;

    // Initialize all philosophers as thinking
    for(i = 0; i < N; i++)
        state[i] = 0;

    // Simulate execution
    for(i = 0; i < N; i++) {
        take_forks(i);
        put_forks(i);
    }

    return 0;
}
