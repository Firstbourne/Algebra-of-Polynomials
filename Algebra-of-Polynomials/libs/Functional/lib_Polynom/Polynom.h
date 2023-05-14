#ifndef LIB_POLYNOM_POLYNOM_H_
#define LIB_POLYNOM_POLYNOM_H_

#include "..\lib_Monom\Monom.h"
#include "..\lib_List\List.h"
//#include "SortedArrayTable.h"

class Polynom {
    List<Monom> monoms;
public:
    Polynom() = default;
    Polynom(std::string);
   // Polynom(std::string expression, SortedArrayTable<std::string,Polynom> *table);
    Polynom(const Polynom& polynom);
    ~Polynom();

    Polynom& operator=(const Polynom& polynom);
    Polynom operator+(const Monom& monom);
    Polynom operator+(const Polynom& polynom);
    Polynom operator-(const Monom& monom);
    Polynom operator-(const Polynom& polynom);
    Polynom operator*(const double x);
    Polynom operator*(const Polynom& polynom);
    Polynom operator/(const double x);
    //Polynom operator/(const Polynom& polynom);
    bool operator==(const Polynom& polynom);
    bool operator!=(const Polynom& polynom);
    bool operator>(const Polynom& polynom);
    bool operator<(const Polynom& polynom);
    bool operator>=(const Polynom& polynom);
    bool operator<=(const Polynom& polynom);

    std::string toString();
    double evaluate(double x, double y, double z);

    Polynom derivative();
    Polynom integral();
};
#endif // !LIB_POLYNOM_POLYNOM_H_