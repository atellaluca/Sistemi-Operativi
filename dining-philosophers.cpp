#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

const int NUM_PHILOSOPHERS = 5;

pthread_t philosophers[NUM_PHILOSOPHERS];
bool hasTakenFork[NUM_PHILOSOPHERS];
int pos;

void initialize(bool boolArray[NUM_PHILOSOPHERS]);
void printStatus(int pos, string message);
void *takeFork(void* forkCount);
void createThread(pthread_t philosophers[NUM_PHILOSOPHERS], int* forkCount);
void signal(int& s);
void wait(int& s);
void initialize(bool hasEaten[NUM_PHILOSOPHERS]);

int main(){
    int forkCount = NUM_PHILOSOPHERS;
    initialize(hasTakenFork);
    bool keepGoing = true;
    while(true){
        createThread(philosophers, &forkCount);
    }
    return 0;
}

void initialize(bool boolArray[NUM_PHILOSOPHERS]){
    for(int i = 0; i < NUM_PHILOSOPHERS; i++){
        boolArray[i] = false;
    }
}

void *takeFork(void* forkCount){
    int n;
    int waitTime, signalTime;
    n = NUM_PHILOSOPHERS / 2;
    pthread_join((long unsigned int)philosophers[pos], 0);
    if(*(int*)forkCount >= n && hasTakenFork[pos] == false){
        wait(*(int*)forkCount);
        hasTakenFork[pos] = true;
        printStatus(pos, "HAS TAKEN THE FORK");
        cout << "Fork count: " << *(int*)forkCount << endl;
        pthread_join(philosophers[pos], 0);
        pthread_exit(0);
    } else if(hasTakenFork[pos] == true && *(int*)forkCount < n){
        printStatus(pos, "IS EATING");
        hasTakenFork[pos] = false;
        signal(*(int*)forkCount);
        cout << "Fork count: " << *(int*)forkCount << endl;
        pthread_exit(0);
    } else if(hasTakenFork[pos] == false && *(int*)forkCount < n){
        printStatus(pos, "IS THINKING");
        pthread_exit(0);
    }
    pthread_exit(0);
}

void createThread(pthread_t philosophers[NUM_PHILOSOPHERS], int* forkCount){
    for(pos = 0; pos < NUM_PHILOSOPHERS; pos++){
        usleep(1000000);
        int thread = pthread_create(&philosophers[pos], NULL, takeFork, (void*)forkCount);
        pthread_join(philosophers[pos], 0);
    }
}

void wait(int& s){
    while(s < 0)
        pthread_exit(0);
    s--;
}

void signal(int& s){
    s++;
}

void printStatus(int pos, string message){
    cout << "PHILOSOPHER: " << pos + 1 << " " << message << endl;
}
