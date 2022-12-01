#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>

std::mutex m;
int x = 0;
void f1()
{
    for (int i = 0; i < 100000; i++)
    {
        std::unique_lock l{m};
        x++;
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1{f1};
    std::thread t2{f1};


    t1.join();
    t2.join();
    std::cout << x << std::endl;
    return 0;
}
