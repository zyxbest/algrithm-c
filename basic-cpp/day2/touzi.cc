#include <iostream>
#include <cstdlib>
using namespace std;

void rolldice(){
  rand();
}

int main(int argc, char const *argv[])
{
  int seed;
  cout << "Enter seed";
  cin >> seed;

  srand(seed);
  return 0;
}
