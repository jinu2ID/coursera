#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

void swap(long long* a, long long* b) {
  long long t = *a;
  *a = *b;
  *b = t;
}

long partition(long long arr[], long low, long high) {
  long long pivot = arr[high];
  long i = (low - 1);
  
  for (long j = low; j <= high-1; j++){
    if (arr[j] <= pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i+1], &arr[high]);
  return (i+1);
}

void quickSort(long long arr[], long low, long high) {
  if (low < high) {
    // partition index
    long pi = partition(arr, low, high);

    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }  

}

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
