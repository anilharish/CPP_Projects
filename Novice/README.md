# Information about NOVICE Projects

Few Interesting C++ Programs to get you started

## DECIMAL TO BINARY
> Using Long Division Method

`pow()` is s `<cmath` function that return the value of base to the power of the exponential its has the syntax `pow(base,exp)`

This code can accept values of upto 4 bytes singed inputs (not recommnded if you have negative values) i.e, input range is from **0** to **2,147,483,647**

## EPSILON

> Using Knuth's Algorithm for comparing floating point values

`fabs()` is a `<cmath>` function that returns absolute value of its parameter. You can use arthematic operators inside `fabs()` function. For example in Knuth's Algorithm:

```cpp

bool epsilon ( double x, double y, double absepsilon, double relepsilon)
{
  double difference = fabs(x-y);
    if( difference <= absepsilon)
      return true;
  return difference <= ((fabs(x) < fabs(y) ? fabs(x):fabs(y))*relepsilon);
}

```
You can change the value of Absoulte Epsilon **absepsilon** and Relative Epsilon **relespilon** in the code to define the comparision limits based on your requirement in the code.