#include "Polynom.h"
#include "../lib_Parser/Parser.h"
#include <sstream>
#include <iomanip>

Polynom::Polynom(std::string str) {
    Parser parser(str);
    monoms = parser.parse();
}

Polynom::Polynom(const Polynom& polynom) {
    monoms = polynom.monoms;
}

Polynom::~Polynom() {
    monoms.resetList();
}

Polynom& Polynom::operator=(const Polynom& polynom) {
    monoms = polynom.monoms;
    return *this;
}

bool Polynom::operator==(const Polynom& polynom) {
    List<Monom> tmp = polynom.monoms;
    if (monoms.size() == tmp.size()) {
        return false;
    }
}
bool Polynom::operator!=(const Polynom& polynom) {
    return !operator==(polynom);
}
//CHECK
bool Polynom::operator>(const Polynom& polynom) {
    Polynom tmp = polynom;
    return this->evaluate(1,1,1) > tmp.evaluate(1,1,1);
}
//CHECK
bool Polynom::operator<(const Polynom& polynom) {
    return !operator>(polynom);
}
//CHECK
bool Polynom::operator>=(const Polynom& polynom) {
    return operator>(polynom) || operator==(polynom);
}
//CHECK
bool Polynom::operator<=(const Polynom& polynom) {
    return !operator>(polynom) || operator==(polynom);
}

//COMPLETED
std::string Polynom::toString() {
    std::string out;
    if (monoms.size() == 0) {
        out += "0";
        return out;
    }
    int i = 0;
    while (i < monoms.size()) {
        Monom monom = monoms.get(i);
        if (monoms.size() == 1)
            out += monom.toString();
        else if (monom.getCoeff() > 0)
            out += "+" + monom.toString();
        else
            out += monom.toString();
        i++;
    }
    return out;
}
//COMPLETED
Polynom Polynom::operator+(const Monom &monom) {
    Polynom result = *this;
    int index = result.monoms.contains(monom);
    if (index != -1) {
        result.monoms.get(index) += monom;
        if (result.monoms.get(index).getCoeff() == 0)
            result.monoms.remove(result.monoms.get(index));
    } else {
        result.monoms.push_back(monom);
    }
    return result;
}

//COMPLETED
Polynom Polynom::operator-(const Monom &monom) {
    Polynom result = *this;
    int index = result.monoms.contains(monom);
    if (index != -1) {
        result.monoms.get(index) -= monom;
        if (result.monoms.get(index).getCoeff() == 0)
            result.monoms.remove(result.monoms.get(index));
    } else {
        result.monoms.push_back(monom);
    }
    return result;
}

//COMPLETED
Polynom Polynom::operator+(const Polynom &polynom) {
    Polynom result = *this;
    List<Monom> tmp = polynom.monoms;
    if (this->monoms.empty() != 1) {
        for (int i = 0; i < result.monoms.size(); i++) {
            int index = tmp.contains(result.monoms.get(i));
            if (index != -1) {
                result.monoms.get(i) += tmp.get(index);
                if (result.monoms.get(i).getCoeff() == 0)
                    result.monoms.remove(result.monoms.get(i));
                tmp.remove(tmp.get(index));
            }
        }
    }
    for (int i = 0; i < tmp.size(); i++) {
        result.monoms.push_back(tmp.get(i));
    }
    return result;
}

//COMPLETED
Polynom Polynom::operator-(const Polynom &polynom) {
    Polynom result = Polynom();
    List<Monom> tmp = polynom.monoms;
    if (this->monoms.empty() != 1) {
        for (int i = 0; i < result.monoms.size(); i++) {
            int index = tmp.contains(result.monoms.get(i));
            if (index != -1) {

                result.monoms.get(i) -= tmp.get(index);
                if (result.monoms.get(i).getCoeff() == 0)
                    result.monoms.remove(result.monoms.get(i));
                tmp.remove(tmp.get(index));

            }
        }
    }
    for (int i = 0; i < tmp.size(); i++) {
        result.monoms.push_back(tmp.get(i));
    }
    return result;
}

//COMPLETED
Polynom Polynom::operator*(const double x) {
    Polynom result = *this;
    for (int i = 0; i < monoms.size(); i++) {
        result.monoms.get(i).setCoeff(result.monoms.get(i).getCoeff() * x);
    }
    return result;
}

//COMPLETED
Polynom Polynom::operator/(const double x) {
    Polynom result = *this;
    for (int i = 0; i < monoms.size(); i++) {
        result.monoms.get(i).setCoeff(result.monoms.get(i).getCoeff() / x);
    }
    return result;
}


//COMPLETED
Polynom Polynom::operator*(const Polynom &polynom) {
    Polynom result = Polynom();
    List<Monom> res;
    List<Monom> tmp = polynom.monoms;
    for (int i = 0; i < monoms.size(); i++) {
        for (int j = 0; j < tmp.size(); j++) {
            res.push_back(monoms.get(i) * tmp.get(j));
        }
    }
    result.monoms = res;
    return result;
}

double Polynom::evaluate(double x, double y, double z) {
    double result = 0;
    for (int i = 0; i < monoms.size(); i++) {
        result += monoms.get(i).evaluate(x,y,z);
    }
    return result;
}
