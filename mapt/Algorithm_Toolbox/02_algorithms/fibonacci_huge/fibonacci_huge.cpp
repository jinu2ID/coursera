#include <iostream>
using std::cout;
using std::endl;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// returns the pisano period for integer m by searching for "01" in the fib squence mod m
long long pisano_period(long long m) {
    long long f0 = 0;
    long long f1 = 1;
    long long pisano = 2;

    if (m == 2)
       return pisano + 1;
 
    for (long long i = 2; i < 6*m; i++){ 
        long long current = (f0 + f1) % m;
        f0 = f1;
        f1 = current;
        pisano++;
 
 	// found "01" sequence
        if ((f0 == 0 && f1 == 1))
           return pisano-2;

    }
    return -1;
}

// calculate the remainder of the fth fib number divided by m
long long get_fib_mod(long long f, long long m) {
    if (f <= 1)
       return f;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < f-1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }    

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m){
    // find length of pisano period for m
    long long pisano = pisano_period(m);
    //cout << "pisano: " << pisano << endl;
    // find n's position in the period 
    long long f = n % pisano;
    //cout << "f: " << f << endl;
            
    return get_fib_mod(f,m);
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cin >> m;
    //std::cout << pisano_period(m) << '\n';
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    cout << get_fibonacci_huge_fast(n, m) << endl;
}
