#include <iostream>

int globalVariable = 50;

struct Demo {
  int memberVar;

  void demo() { std::cout << "Hello from the class!" << std::endl; }
};

int square(int a) { return a * a; }

namespace LLDBDemo {
int add(int a, int b) { return a + a; }
} // namespace LLDBDemo

int main(int argc, char *argv[]) {
  if (argc > 1) {
    std::cout << argv[1] << std::endl;
  }
  int value = 5;
  int result1 = square(value);
  std::cout << result1 << std::endl;

  Demo d;
  d.demo();

  int result2 = square(10);
  std::cout << result2 << std::endl;

  globalVariable = 75;

  d.memberVar = 10;
  d.memberVar = 0;

  return 0;
}