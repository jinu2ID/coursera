#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

void printVectors(vector<double> values, vector<double> weights)
{
  for (int i = 0; i < values.size(); i++) {
    cout << values[i] << " " << weights[i] << endl;
  }
}

int partition (vector<double> &values, vector<double> &weights, int low, int high) 
{ 
  double pivot = values[high]/weights[high];
  int i = (low - 1);

  for (int j = low; j <= high-1; j++)
  {
    double valuePerWeight = values[j]/weights[j];
    if (valuePerWeight <= pivot)
    {
      // move wall 1 space to right, elements to the left are smaller than pivot, 
      // elements to the right are larger than pivot
      i++; 
      swap(values[i], values[j]);
      swap(weights[i], weights[j]);
    }
  }

 swap(values[i+1], values[high]);
 swap(weights[i+1], weights[high]);

 return (i+1);
  
}

void quickSort(vector<double> &values, vector<double> &weights, int low, int high)
{
  if (low < high) {
    int pivot = partition(values, weights, low, high);
    quickSort(values, weights, low, pivot-1);
    quickSort(values, weights, pivot+1, high);
  } 
}



double get_optimal_value(int n, long capacity, vector<double> values, vector<double> weights) {
  double value = 0.0;
  quickSort(values, weights, 0, n-1);
  
  int i = n-1;
  while (capacity > 0 && i >= 0) {
    double amount = weights[i];
    
    if (amount > capacity) {
      amount = capacity;
    }
  
    capacity -= amount;  
    value += amount*((double)values[i]/(double)weights[i]);
    
    i--;

  }
  return value;
}



int main() {
  int n;
  long capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  
  double optimal_value = get_optimal_value(n, capacity, values, weights);

  std::cout.precision(10);
  std::cout << fixed << setprecision(4) << optimal_value << std::endl;
  return 0;
}
