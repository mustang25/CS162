//************************************************************
//Date: 10/15/2015
//Description: This is the LoadedDie class specification file.
//             This class also inherites values from the die class
//************************************************************
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

class LoadedDie:public Die
{
   public:
      LoadedDie();
      LoadedDie(int *sidesIn);
      int roll();
};
#endif
