#ifndef __SAFE_DEPO__
#define __SAFE_DEPO__

#include <iostream>
#include "valuable.h"

class SafeDeposit
{
public:
  bool add(Valuable &_val)
  {
    bool retVal = false;
    int ret = whereToFit(_val.getVolume());
    if (ret == -1)
      return retVal;

    unsigned int _cnt = safes[ret];

    if (_cnt > 0)
    {

      safes[ret] -= 1;
      retVal = true;
    }
    else
    {
      retVal = false;
    }

    return retVal;
  }

  const int SMALL = 0;
  const int MEDIUM = 1;
  const int LARGE = 2;
  unsigned int safeCnt;
  SafeDeposit(unsigned int _small, unsigned int _medium, unsigned int _large)
  {

    safes[SMALL] = _small;
    safes[MEDIUM] = _medium;
    safes[LARGE] = _large;
    safeCnt = _small + _medium + _large;
  }

  void print()
  {
    printf("\n\r Total safe=%u. Small %u  Medium %u Large %u  available to use ", safeCnt, safes[SMALL], safes[MEDIUM], safes[LARGE]);
  }

private:
  unsigned int safes[3];
  unsigned int maxSafe = 10;
  int whereToFit(unsigned int _volume)
  {
    
    if (_volume > 0 && _volume <= 10)
      return SMALL;
    else if (_volume > 10 && _volume <= 20)
      return MEDIUM;
    else if (_volume > 20 && _volume <= 30)
      return LARGE;
    else
      return -1;
  }
};

#endif