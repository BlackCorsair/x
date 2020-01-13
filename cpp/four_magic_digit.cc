#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T> void print_vector(const std::vector<T> &v) {
  std::cout << "{ ";
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << "}" << std::endl;
}

int vector_to_int(const std::vector<int> &vector) {
  int result = 0;

  for (int i = 0; i < vector.size(); ++i) {
    result += vector.at(i) * std::pow(10, vector.size() - 1 - i);
  }

  return result;
}

std::vector<int> int_to_vector(int number) {
  std::vector<int> result{};

  while (number > 0) {
    result.insert(result.begin(), number % 10);
    number = number / 10;
  }

  if (result.size() < 4) {
    result.insert(result.begin(), 0);
  }

  return result;
}

std::vector<int> four_magic_number(const std::vector<int> &digits) {
  if (vector_to_int(digits) == 6174) {
    std::cout << "yay!" << std::endl;
    return {6, 1, 7, 4};
  }

  std::vector<int> ascend = digits;
  std::sort(ascend.begin(), ascend.end(), std::greater<int>());
  int ascend_number = vector_to_int(ascend);

  std::vector<int> descend = digits;
  std::sort(descend.begin(), descend.end());
  int descend_number = vector_to_int(descend);

  std::vector<int> magic_digits = int_to_vector(
      (ascend_number < descend_number) ? descend_number - ascend_number
                                       : ascend_number - descend_number);

  std::cout << "\nGiven: ";
  print_vector(digits);
  std::cout << "Magic number calculated is: ";
  print_vector(magic_digits);

  return four_magic_number(magic_digits);
}

int main(int argc, char const *argv[]) {

  std::vector<int> digits{1, 5, 4, 7};
  int number = 1547;

  four_magic_number(digits);

  return 0;
}