#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

long long MaxPairwiseProduct(const vector<long long>& numbers) {
  long long result = 0;
  long long n = numbers.size();
  for (long long i = 0; i < n; ++i) {
    for (long long j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
//        cout << numbers[i] << " " << numbers[j] << endl;
        result = numbers[i] * numbers[j];
//        cout << result << endl;
      }
    }
  }
  return result;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> numbers(n);
    for (long long i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
