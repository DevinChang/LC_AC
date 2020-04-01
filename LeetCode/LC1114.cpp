#include <bits/stdc++.h>
using namespace std;


/*
多线程编程：按序打印
三个不同的线程将会共用一个 Foo 实例。
线程 A 将会调用 one() 方法
线程 B 将会调用 two() 方法
线程 C 将会调用 three() 方法
*/

/*
思路：三个线程共享有明显的同步关系，即线程B必须在线程A之后，线程C在线程B之后。
所以可以用信号量来控制同步关系
*/


class Foo{
    sem_t first_jon, second_job;
public:
    Foo(){
        sem_init(&first_job, 0, 0);
        sem_init(&second_job, 0, 0);
    }

    void first(function<void()> printFirst){
        printFirst();
        sem_post(&first_job);
    }

    void second(function<void()> printSecond){
        sem_wait(&first_job); // 等待线程A完成
        printSecond();
        sem_post(&second_job);
    }

    void third(function<void()> printThird){
        sem_wait(&second_job) ;
        printThird();
    }
}




int main(){



    return 0;
}