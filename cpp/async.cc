#include <cmath>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

long long tedious_calculation(int x) { return x * x; }

long long recursion_magic(int n) {
  if (n == 1) return 1;
  return n * recursion_magic(n - 1);
}

void tasking(void) {
  std::vector<std::thread> thread_list;
  std::vector<std::future<long long>> futures;

  for (int i = 0; i < 100; ++i) {
    if (i % 2 == 0) {
      std::packaged_task<long long(int)> task(tedious_calculation);
      futures.push_back(task.get_future());
      thread_list.push_back(std::thread(std::move(task), i));
    } else {
      std::packaged_task<long long(int)> task(recursion_magic);
      futures.push_back(task.get_future());
      thread_list.push_back(std::thread(std::move(task), i));
    }
  }

  for (auto& thread : thread_list) {
    thread.join();
  }

  for (auto& future : futures) {
    std::cout << "future:\t" << future.get() << "\n";
  }
}

void async(void) {
  std::vector<std::future<long long>> futures;

  for (int i = 0; i < 100; ++i) {
    if (i % 2 == 0) {
      futures.push_back(std::async(&tedious_calculation, i));
    } else {
      futures.push_back(std::async(&recursion_magic, i));
    }
  }

  for (auto& future : futures) {
    std::cout << "future:\t" << future.get() << "\n";
  }
}

int main() { async(); }
