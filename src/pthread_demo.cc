#include <pthread.h>
#include <iostream>

#define THREAD_N 10

struct cal_pachage
{
    int* scores;
    int index;
};


void *cal(void * v)
{
    double num = 0;
    cal_pachage * p = (cal_pachage*)v;
    for (size_t i = 0; i < 2000; i++)
    {
        for (size_t j = 0; j < 2000; j++)
        {
            for (size_t k = 0; k < 2000; k++)
            {
                num += 1.1;
            }
            
        }
        
    }
    
    pthread_exit(NULL);
    
}

int scores[THREAD_N] = { 0 };
cal_pachage p[THREAD_N];


int main()
{
    for (size_t i = 0; i < THREAD_N; i++)
    {
        p[i].scores = scores;
        p[i].index = i;
    }
    

    pthread_t tids[THREAD_N];
    for (size_t i = 0; i < THREAD_N; i++)
    {
        pthread_create(&tids[i], NULL, cal, (void *)(&p[i]));
    }
    for (size_t i = 0; i < THREAD_N; i++)
    {
        pthread_join(tids[i], NULL);
    }
    
    pthread_exit(NULL);

}