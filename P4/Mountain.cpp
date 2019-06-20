#include "Mountain.h"
std::ostream& operator<<(std::ostream& os, const Mountain& obj)
{
    os << obj.to_String();
    return os;
}

