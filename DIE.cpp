#include "DIE.h"

Die::Die() {
    m_numberOfSides = 6;
    setValue();
}

void Die::set_numOfSides(int numOfSides) {
    switch (numOfSides) {
        case 4:
            m_numberOfSides = 4;
            break;
        case 6:
            m_numberOfSides = 6;
            break;
        case 8:
            m_numberOfSides = 8;
            break;
        default:
            m_numberOfSides = 6;
    }
}
int Die::getNumOfSides() {
    return m_numberOfSides;
}

void Die::setValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, m_numberOfSides);
    m_value = dist(gen);
}
int Die::getValue() {
    return m_value;
}
#include "DIE.h"