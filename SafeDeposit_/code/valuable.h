#ifndef __VALUABLE__
#define __VALUABLE__

#include <iostream>
class  Valuable
{
private:
char name[10];
unsigned int volume;

public:
unsigned int getVolume(){return volume;}
char * getName(){return name;}
Valuable(const char* _name, unsigned int _volume)
{
  memcpy(name,_name,10);
  volume=_volume;
}
void print()
{
  printf("\n\r name:%s volume:%u",name,volume);
}

};
#endif