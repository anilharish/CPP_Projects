#include <iostream>
#include <cmath>

long checkdigit(long number, long divider);
long numberinput();
long getdivider( long number);

int main ()
{
  long input {},power{},divider{};
  long spacing{1}, checkspacing{};
  input = numberinput();
  power = getdivider (input);
  divider = std::pow( 2, power);

  std::cout << "Nearest number to power of 2: " << divider << "\n";
  std::cout << "The binary equivalent of the number is: ";

  while ( divider >= 1)
    {
      input = checkdigit ( input, divider);
      divider /=2;
      checkspacing=spacing%4;
      if (checkspacing==0)
	{
	  std::cout << " ";
	}
      spacing +=1;
    }

  std::cout << "\n";
  
  return 0;
}

long checkdigit( long input, long divider)
{
  if (input >= divider)
    {
      std::cout << "1";
      return input-divider;
    }
  else
    {
      std::cout << "0";
      return input;
    }
}  

long numberinput()
{
  long a{};
  std::cout << "Please enter a number to get its binary equivalent\n";
  std::cin >> a;
  return a;
}

long getdivider(long number)
{
  long a{0};
  while (number > 0)
    {
      number/=2;
      a=a+1;
    }
  return a;
}
