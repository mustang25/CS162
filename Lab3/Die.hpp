//*****************************************************
//Date: 10/15/2015
//Description: This is the Die Class specification file.
//*****************************************************
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
   protected:
      int sides;
   public:
      Die();
      Die(int *sidesIn);
      int roll();
};
#endif

