#include<iostream>
#include<cmath>

bool epsilon( double x, double y, double absepsilon, double relepsilon);
double inputnumbers(int x);

int main ()
{
  double a{0.0}, b{0.0};
  a=inputnumbers(1);
  b=inputnumbers(2);
  if (epsilon (a,b,1e-12,1e-8))
    std::cout << a << " is equal to " << b << "\n";
  else
    std::cout << a << " is not equal to " << b <<"\n";
  return 0;
}
  
bool epsilon ( double x, double y, double absepsilon, double relepsilon)
{
  double difference = fabs(x-y);
    if( difference <= absepsilon)
      return true;
  return difference <= ((fabs(x) < fabs(y) ? fabs(x):fabs(y))*relepsilon);
}

double inputnumbers (int x)
{
  double a{0.0};
  std::cout << "Please input the number : " << x << "\n";
  std::cin >> a;
  return a;
}
