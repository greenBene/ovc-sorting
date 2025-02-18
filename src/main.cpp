#include <iostream>


int multiply(int a, int b) {
  return a * b;
}


int main(int argc, char *argv[]) {
  int a = 5;
  int b = 6;

  std::cout << a << " * " << b << " = " << multiply(a,b)  << std::endl;
  return 0;
}

