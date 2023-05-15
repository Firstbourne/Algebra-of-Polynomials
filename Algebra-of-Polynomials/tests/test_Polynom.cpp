#include "gtest/gtest.h"
#include "../libs/Functional/lib_Polynom/Polynom.cpp"
#include "../libs/Functional/lib_Polynom/Polynom.h"

TEST(Polynom_op, Polynom_to_polynom) {
    int* powers1 = new int[3] {1, 2, 3};
    Monom m1(2, 3, powers1);
    int* powers2 = new int[3] {3, 2, 1};
    Monom m2(3, 3, powers2);
    List<Monom> monoms;
    monoms.push_back(m1);
    monoms.push_back(m2);
    Polynom p1;

    Polynom p2;
    p2 = p1;

    assert(p1 == p2);
}

