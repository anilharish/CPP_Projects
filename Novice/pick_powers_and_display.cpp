#include <iostream>
#include <bitset>

int pickpower1();
int pickpower2(int firstpower);

int main()
{
  const unsigned int fire      = 0;
  const unsigned int water     = 1;
  const unsigned int earth     = 2;
  const unsigned int air       = 3;
  const unsigned int lightning = 4;
  const unsigned int poison    = 5;
  const unsigned int paralysis = 6;
  const unsigned int speed     = 7;

  const unsigned int redbitmask = 0xFF000000;
  const unsigned int greenbitmask = 0x00FF0000;
  const unsigned int bluebitmask = 0x0000FF00;
  const unsigned int alphabitmask = 0x000000FF;

  std::bitset<8> powers{0};
  int power1{0},power2{0};
  power1=pickpower1();
  power2=pickpower2(power1);

  if (power1 == 1 && power2 == 2)
    {
      powers.set(fire);
      powers.set(water);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 1 && power2 == 3)
    {
      powers.set(fire);
      powers.set(earth);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 1 && power2 == 4)
    {
      powers.set(fire);
      powers.set(air);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 1 && power2 == 5)
    {
      powers.set(fire);
      powers.set(lightning);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 1 && power2 == 6)
    {
      powers.set(fire);
      powers.set(poison);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 1 && power2 == 7)
    {
      powers.set(fire);
      powers.set(paralysis);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 1 && power2 == 8)
    {
      powers.set(fire);
      powers.set(speed);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 2 && power2 == 1)
    {
      powers.set(water);
      powers.set(fire);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 2 && power2 == 3)
    {
      powers.set(water);
      powers.set(earth);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 2 && power2 == 4)
    {
      powers.set(water);
      powers.set(air);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 2 && power2 == 5)
    {
      powers.set(water);
      powers.set(lightning);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 2 && power2 == 6)
    {
      powers.set(water);
      powers.set(poison);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 2 && power2 == 7)
    {
      powers.set(water);
      powers.set(paralysis);
	std::cout << "Power combination Code: " << powers << "\n";
    }
  else if (power1 == 2 && power2 == 8)
    {
      powers.set(water);
      powers.set(speed);
	std::cout << "Power combination Code: " << powers << "\n";
    }

  unsigned int pixel{0};

  std::cout << "Please enter the RGBA Hexadecimal Value for your screen in the format FFFFFFFF\n";
  std::cin >> std::hex >> pixel;
  
  unsigned char red = (pixel & redbitmask) >> 24;
  unsigned char green = (pixel & greenbitmask) >> 16;
  unsigned char blue = (pixel & bluebitmask) >> 8;
  unsigned char alpha = (pixel & alphabitmask) >> 0;

  std::cout << "Your colour contains: \n";
  std::cout << static_cast<int>(red) << " of 255 RED\n";
  std::cout << static_cast<int>(green) << " of 255 GREEN\n";
  std::cout << static_cast<int>(blue) << " of 255 BLUE\n";
  std::cout << static_cast<int>(alpha) << " of 255 ALPHA\n";

  return 0;
}
  
int pickpower1()
{
  int a{0},b{0};
  std::cout << "Refer to the table below for corresponding power and number associated with it:\n1 = Fire\n2 = Water\n3 = Earth\n4 = Air\n5 = Lightning\n6 = Poison\n7 = Paralysis\n8 = Speed\n";
  std::cout << "Please enter Fire or Water number for 1st Power\n";
  std::cin >> a;
  while ( b!=1)
    {
      if ( a == 1 || a == 2)
	{
	  b=1;
	  return a;
	}
      else
	{
	  std::cout << "You can only select Fire or Water as the first power\n";
	  std::cout << "Please re-enter Fire or Water number for 1st power\n";
	  std::cin >> a;
	}
    }
}

int pickpower2(int firstpower)
{
  int a{0},b{0};
  std::cout << "Please enter the number for 2nd power\n";
  std::cin >> a;
  while (b!=1)
    {
      if ( a==firstpower)
	{
	  std::cout << "You cannot pick the same power twice\n";
	  std::cout << "Please re-enter the second power\n";
	  std::cin >> a;
	}
      else
	{
	  b=1;
	  return a;
	}
    }
}
