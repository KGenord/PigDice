#ifndef PIGDICE_DIE_H
#define PIGDICE_DIE_H
#include <random>



 class Die {
 private:
     int m_dieValue;
 public:
     Die();
     void rollDie();
     int getDieValue() const;
 };



#endif //PIGDICE_DIE_H