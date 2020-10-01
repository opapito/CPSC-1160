# include <iostream>

int main() {
  int x, y, sum;
  std::cerr << "A program which adds two integers\n";
  std::cerr << "Enter 1st integer: ";
  std::cin >> x;
  std::cerr << "Enter 2nd integer: ";
  std::cin >> y;
  std::cerr << "\n";
  sum = x + y;
  std::cout << "Sum is " << sum << std::endl;
  return 0;
}