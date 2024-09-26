#include "ThreadPool.h"
#include "ThreadPool.cpp"
#include <iostream>
#include <unistd.h>
using namespace std;
void taskFunc(void* arg)
{
    int num = *(int*)arg;
    cout << "thread_id: " << pthread_self() << " taskFunc: " << num << endl;
    sleep(1);
}


int main()
{
    ThreadPool<int> pool(3,10);
    for(int i = 0; i < 100; ++i)
    {
        int *num = new int(i + 100);
        pool.addTask(Task<int>(taskFunc,num));
    }

    sleep(20);

    return 0; 
}