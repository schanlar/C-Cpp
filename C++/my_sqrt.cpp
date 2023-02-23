# include <iostream>
# include <cstdlib>
# include <cmath>

using namespace std;

// Function prototype
double mySqrt(double x);

int main(){

  // Test the function
  cout << "Square root: "<< mySqrt(4.0) << endl;
  cout << "Square root: "<< mySqrt(16.0) << endl;
  cout << "Square root: "<< mySqrt(2.0) << endl;
  return 0;
}


double mySqrt(double x){

  double a = 0.0;
  double b = x;

  double eps = 1e-6;

  double guess = (a + b) / 2.0;

  while (abs(pow(guess, 2) - x) > eps){

    if (pow(guess, 2) < x){
      a = guess;
      guess = (a+b)/2.0;
    }
    else {
      b = guess;
      guess = (a+b)/2.0;
    }
  }

  return guess;
}
