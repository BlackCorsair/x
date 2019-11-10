/*
    Copyright
 */

#include <iostream>
#include <thread>
#include <vector>
#include <string>

void repeat(const char* string) {
    for (int i = 0; i < 5; ++i) {
        std::cout << string << std::endl;
    }
}

void printText(void) {
    std::cout << "B1" << std::endl;
    std::cout << "B2" << std::endl;
    std::cout << "B3" << std::endl;
}

int main(int argc, char const *argv[]) {
    std::vector<std::thread> threads;

    threads.emplace_back(repeat, "asdf");
    threads.emplace_back(repeat, "asdf");
    threads.emplace_back(printText);

    for (auto& thread : threads) {
        thread.join();
    }
    return 0;
}
