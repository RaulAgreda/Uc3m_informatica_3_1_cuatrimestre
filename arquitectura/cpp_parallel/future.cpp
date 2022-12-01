#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <future>

int calculate_n_sum(int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
        total += i;
    return total;
}

int main(int argc, char const *argv[])
{
    std::future<int> r = std::async(calculate_n_sum, 100000000);
    std::cout << "resultadito a continuasion papito\n";
    std::cout << r.get() << std::endl;
    return 0;
}
