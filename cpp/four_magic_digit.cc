#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
int print_vector(const std::vector<T>& v, bool first_called) {
  if (v.size() == 1) {
    std::cout << v.front() << " }" << std::endl;
    return 1;
  }
  if (first_called) {
    std::cout << "{ " << v.front() << " ";
  } else {
    std::cout << v.front() << " ";
  }

  std::vector<int> reduced{v.begin() + 1, v.end()};
  return print_vector(reduced, false);
}

template <typename Iterator>
int vector_to_int(const Iterator& begin, const Iterator& end) {
  if (begin + 1 == end) {
    return *begin;
  }

  return *begin * std::pow(10, end - begin - 1) + vector_to_int(begin + 1, end);
}

std::vector<int> concatenate_vectors(const std::vector<int>& v1,
                                     const std::vector<int>& v2) {
  std::vector<int> v3 = v1;
  v3.insert(v3.end(), v2.begin(), v2.end());
  return v3;
}

std::vector<int> int_to_vector(int number) {
  if (number < 10) {
    return {number};
  }

  std::vector<int> v{number % 10};

  return concatenate_vectors(int_to_vector(number / 10), v);
}

std::vector<int> four_magic_number(const std::vector<int>& digits) {
  if (vector_to_int(digits.begin(), digits.end()) == 6174) {
    std::cout << "yay!" << std::endl;
    return {6, 1, 7, 4};
  }

  std::vector<int> ascend = digits;
  std::sort(ascend.begin(), ascend.end(), std::greater<int>());
  int ascend_number = vector_to_int(ascend.begin(), ascend.end());

  std::vector<int> descend = digits;
  std::sort(descend.begin(), descend.end());
  int descend_number = vector_to_int(descend.begin(), descend.end());

  std::vector<int> magic_digits = int_to_vector(
      (ascend_number < descend_number) ? descend_number - ascend_number
                                       : ascend_number - descend_number);

  std::cout << "\nGiven: ";
  print_vector(digits, true);
  std::cout << "Magic number calculated is: ";
  print_vector(magic_digits, true);

  return four_magic_number(magic_digits);
}

int main(int argc, char const* argv[]) {
  if (argc < 2) {
    std::cout << "You need to provide a number!!!" << std::endl;
    std::cout << "example: <executable> 1234" << std::endl;
    return -1;
  }

  std::vector<int> digits = int_to_vector(atoi(argv[1]));

  four_magic_number(digits);

  return 0;
}