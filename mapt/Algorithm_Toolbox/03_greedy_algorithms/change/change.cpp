#include <iostream>
using std::cout;
using std::endl;

int get_change(int m) {
  
  // Calculate 10s coins needed
  int tens = m/10;
  int fives = 0;
  int ones = 0;
  int remainder = m%10;
  //cout << "10s rem: " << remainder << endl;

  // Calculate 5s coins needed
  if (remainder > 0) {
    fives = remainder/5;
    remainder = m%5;
    
    // Calculate 1s coins needed
    ones = remainder; 
  }

  //cout << "10s: " << tens << " 5s: " << fives << " 1s: " << ones << endl;
  return tens + fives + ones;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
