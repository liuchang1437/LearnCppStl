#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
void print_vector(vector<int> &vec) {
  for (auto n : vec) cout << n << " ";
  cout << endl;
}
int main() {
  vector<int> num{ 0, 1, 2, 3, 4, 5, 6, 7 };

  cout << "before make_heap: ";
  print_vector(num);

  cout << "after make_heap: ";
  make_heap(num.begin(), num.end());
  print_vector(num);


  cout << "after push_heap: ";
  num.push_back(9);
  push_heap(num.begin(), num.end());
  print_vector(num);

  cout << "after pop_heap: ";
  pop_heap(num.begin(), num.end());
  print_vector(num);

  cout << "biggest number: " << num.back() << endl;
  num.pop_back();

  cout << "pop the biggest: ";
  print_vector(num);

  cout << "min heap: ";
  make_heap(num.begin(), num.end(), greater<int>());
  print_vector(num);

  cout << "after sort the arr: ";
  sort_heap(num.begin(), num.end(), greater<int>());
  print_vector(num);

  return 0;
}