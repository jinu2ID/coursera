#include <iostream>
using std::cout;
using std::endl;

long long fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum = (sum + current) % 10;
    }

    return sum % 10;
}

// use the pisano period of fib mod 10 to get fib sum mod 10
int fibonacci_sum_fast(long long n) {
   if (n <= 1)
       return n;

   int f = n % 60; // 60 is the pisano period for 10
   //cout << "f: " <<  f << endl;
   if (f <= 1)
      return f;
    
   int previous = 0;
   int current = 1;
   int sum = 1;

   for (int i = 0; i < f-1; i++) {
       int tmp_previous = previous;
       previous = current;
       current = (tmp_previous + current) % 10;
       sum = (sum + current) % 10;
       //cout << i+2 << ": " << sum << endl;
   }

   return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n) << endl;
    /*for (int i = 0; i < 60; i++) {
        cout << i << ": " << fibonacci_sum_naive(i) << endl;
    }*/
}
