#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

vector<int> input() {
  size_t n;
  cout << "input numbers";
  cin >> n;
  //   int arr[n];
  vector<int> arr;
  while (n--) {
    int a;
    cin >> a;
    arr.push_back(a);
  }

  return arr;
}

void print(vector<int> arr) {
  copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

void foreachPrint(vector<int> arr) {
  for (auto item : arr) {
    cout << item << " ";
  }
  cout << endl;
}
void section(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    int min = i;
    for (int j = 1; j < arr.size(); j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
}

int main(int argc, char const *argv[]) {
  vector<int> a = input();
  section(a);
  print(a);
  foreachPrint(a);
  return 0;
}
