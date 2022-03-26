#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long sumTwoSmallestNumbers(std::vector<int> numbers) {
  sort(numbers.begin(), numbers.end());

  return numbers[0]+numbers[1];
}

int main(int argc, char const *argv[]) {
  /*   vector<int > arr;
    for(int i = 0 ;i<5;i++)
    cin >> arr[i]; */
  vector<int> arr = {12, 31, 21, 23, 3};
  cout << sumTwoSmallestNumbers(arr) << "\n";
  for (int i : arr)
    cout << i << " ";
  return 0;
}
