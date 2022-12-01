#include <iostream>
#include <unistd.h>
#include <thread>

void f1(int x)
{
    std::cout << "Hey que tal soy 1 " << x <<"\n";
}
void f2()
{
    std::cout << "Hey que tal soy 2\n";
}

int main(int argc, char **argv)
{
    std::thread t1{f1, 42};
    std::thread t2{f2};
    std::thread t3{[&]{
        int x = 0;
        while (x < 100)
            std::cout << x++ << " ";
        std::cout << "\n";
    }};

    t1.join();
    t2.join();
    t3.join();
    std::cout << "done\n";
    

}