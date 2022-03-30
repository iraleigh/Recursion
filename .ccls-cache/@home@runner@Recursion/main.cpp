#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// n = 10
// n = 9
// n = 8
// ...
// n = 2
// n = 1
// n = 0
void printForward(int n) {
  if (n == 0) return;

  printForward(n-1);
  
  cout << n << endl;
}


// n = 10
// n = 9
// n = 8
// ...
// n = 1
// n = 0
void printBackward(int n) {
  if (n == 0) return;
  
  cout << n << endl;

  printBackward(n-1);
}

int next(list<int>& arr) {
  int next = arr.front();
  arr.pop_front();
  return next;
}

void printListForward(list<int> arr) {
  if (arr.size() == 0) return; // base

  int n = next(arr); // make it smaller
  
  cout << n << endl; // operation
  printListForward(arr); // recursive step
}

void printListBackward(list<int> arr) {
  if (arr.size() == 0) return;
  
  int n = next(arr);
  printListBackward(arr);
  cout << n << endl;
}

// Return the Nth Fibonacci Number
// 1, 1, 2, 3, 5, 8, 13
// with the basic recusive approach
// we end up resolving the same problems
//               n=5
//         n=4              n=3
//     n=3     n=2      n=2   n=1
//  n=2  n=1 n=1 n=0  n=1 n=0
//n=1 n=0
// Using a simple memoization approach
// we can reduce the recursive calls
//               n=5
//         n=4              
//     n=3           
//  n=2  
//n=1 n=0

unordered_map<int, int> fibMemo;

int fib(int n) {
  if (n <= 1) return n;

  // if I don't find it in fibMemo
  if (fibMemo.count(n) < 1) {
    fibMemo[n] = fib(n-1) + fib(n-2);
  }

  return fibMemo[n];
}

// You are climbing a staircase. It takes n steps to reach the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

unordered_map<int, int> memo;
int climbStairs(int n) {
  if (n <= 2) return n;

  if (memo.count(n) < 1) {
    memo[n] = climbStairs(n-1) + climbStairs(n-2);
  }
  
  return memo[n];
}

int main() {
  // int n = 10;
  
  // cout << "Print nums 1 to " << n << endl;
  // printForward(n);


  // cout << "Print nums " << n << " to 1" << endl;
  // printBackward(n);

  // list<int> arr { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  // cout << "Print list forwards " << endl;
  // printListForward(arr);
  
  // cout << "Print list backwards " << endl;
  // printListBackward(arr);

  // cout << "Print nth fibonacci number" << endl;
  // cout << fib(10) << endl;

  cout << "Climb N stairs" << endl;
  cout << climbStairs(10) << endl;
}