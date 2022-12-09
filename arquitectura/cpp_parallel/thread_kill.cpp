#include <iostream>
#include <thread>
#include <fstream>

void f1(int n)
{
	unsigned int total = 0;
	for (int i = 0; i < n; i++)
		total += i;
	std::ofstream ofs{"killed_thread.txt"};
	ofs << "Thread killed " << total << std::endl;
	ofs.close();
}

int main(int argc, char const *argv[])
{
	std::thread t1{f1, 1000000000};
	// t1.detach();
	// t1.join();
	std::cout << "Se acabó, a mimir" << std::endl;
	return 0;
}
