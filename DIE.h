#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H
#include <random>



 class Die {
 private:
     int m_value;
     int m_numberOfSides;
 public:
     Die();
     void set_numOfSides(int numOfSides);
     int getNumOfSides();
     void setValue();
     int getValue();
 };



#endif //PIGDICE_DIE_H