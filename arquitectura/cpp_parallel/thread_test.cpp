#include <iostream>
#include <unistd.h>
#include <thread>

void f1()
{
    sleep(1);
    std::cout << "Hey que tal soy 1\n";
}
void f2()
{
    std::cout << "Hey que tal soy 2\n";
}


int main(int argc, char **argv)
{
    std::thread t1{f1};
    std::thread t2{f2};

    t1.join();
    t2.join();
    std::cout << "done\n";
    

}