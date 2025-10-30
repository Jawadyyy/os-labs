#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ATMS 3
#define OPS_PER_ATM 5

long long balance = 1000;          
pthread_mutex_t balance_lock;       

void *atm_thread(void *arg) {
    int id = *(int *)arg;        
    printf("ATM %d started\n", id);

    for (int op = 0; op < OPS_PER_ATM; ++op) {
       pthread_mutex_lock(&balance_lock);  

        if (op % 2 == 0) {
            long long amount = 100;
            if (balance >= amount){
                balance -= amount;
                printf("ATM %d withdrew %lld | Balance: %lld\n", id, amount, balance);
            }
            else {
                printf("ATM %d tried to withdraw %lld but insufficient funds!\n", id, amount);
            }
        }
        else  {
            long long amount = 50;
            balance += amount;
            printf("ATM %d deposited %lld | Balance: %lld\n", id, amount, balance);
        }

        pthread_mutex_unlock(&balance_lock); 
    }

    printf("ATM %d finished\n", id);

    return NULL;
}

int main() {
    pthread_t atms[NUM_ATMS];
    int ids[NUM_ATMS];

    pthread_mutex_init(&balance_lock, NULL);

    printf("Starting bank system | Initial Balance: %lld\n", balance);

    for (int i = 0; i < NUM_ATMS; i++) {
        ids[i] = i + 1;
        pthread_create(&atms[i], NULL, atm_thread, &ids[i]);
    }


    for (int i = 0; i < NUM_ATMS; i++) {
        pthread_join(atms[i], NULL);
    }

    printf("All ATMs done | Final Balance: %lld\n", balance);

    pthread_mutex_destroy(&balance_lock);
    return 0;
}
