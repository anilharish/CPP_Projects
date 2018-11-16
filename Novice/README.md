# Information about NOVICE Projects

Few Interesting C++ Programs to get you started

## DECIMAL TO BINARY
> Using Long Division Method

`pow()` is a `<cmath>` library function that return the value of base to the power of the exponential its has the syntax `pow(base,exp)`

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

## PICK POWERS AND DISPLAY

> Using <bitset> library in C++

`std::bitset<8> bits(0x2);` is a <bitset> library function that helps in manipulation of bitflags. It provides 4 key functions

**NOTE: ** _With std::bitset, our options correspond to the bit indices, not the bit patterns itself_

```cpp
bits.set(option1); // set bit 1 to 1. Option 1 is a const int which needs to be declared.
bits.fip(option2); // flip bit 2.
bits.reset(opton2); // resets bit 2 back to 0.

std::cout << "Bit 2 has value: " << bits.test(option2) <<"\n"; \\ check the current value of bit 2

````
Has built in test for inputs for powers but not for display settings.