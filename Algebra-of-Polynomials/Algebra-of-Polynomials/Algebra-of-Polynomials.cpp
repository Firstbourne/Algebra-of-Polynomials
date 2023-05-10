// Algebra-of-Polynomials.cpp: определяет точку входа для приложения.
//

#include "Algebra-of-Polynomials.h"
#include "Polynom.h"
#include "ChainMethodTable.h"
#include "OpenShuffleTable.h"
#include "LinearListTable.h"
#include "LinearArrayTable.h"
#include "SortedArrayTable.h"
#include "AVLTreeTable.h"

using namespace std;

int main()
{
    int powers[] = {2, 0, 2};
    Monom monom = Monom(2, 3, powers);
    monom.toString();
    cout << endl;

    string pol1 = "3.2x^2y^3z - 1.3xz^4 + 1.3xz^4";
    Polynom polynom1 = Polynom(pol1);
    cout << "Polynom1 = " << polynom1.toString() << endl;

    Polynom polynom2 = Polynom("-3.2x^2y^3z");
    cout << "Polynom2 = " << polynom2.toString() << endl;

    Polynom polynom3 = Polynom("-1.3xz^4");
    cout << "Polynom3 = " << polynom3.toString() << endl << endl;

    /*cout << "Polynom1 at (1,1,1) = " << polynom1.evaluate(1, 1, 1) << endl;

    Polynom plusPolynom = polynom1 + polynom2;
    cout << "Polynom1 + Polynom2 = " << plusPolynom.toString() << endl;

    Polynom minusPolynom = polynom1 - polynom2;
    cout << "Polynom1 - Polynom2 = " << minusPolynom.toString() << endl;

    Polynom multPolynom = polynom1 * 10;
    cout << "Polynom1 * 10 = " << multPolynom.toString() << endl;

    Polynom multPPolynom = polynom1 * polynom3;
    cout << "Polynom1 * Polynom3 = " << multPPolynom.toString() << endl;
    cout << endl << endl;
    */

    ChainMethodTable<std::string, Polynom> chainTable;
    chainTable.insert("Pol_1", polynom1);
    chainTable.insert("Pol_2", polynom2);
    chainTable.insert("Pol_3", polynom3);
    chainTable.print();
    cout << endl;

    chainTable.remove("Pol_2");
    chainTable.print();
    cout << endl;

    chainTable.remove("Pol_10");
    cout << endl << endl;

    OpenShuffleTable<std::string, Polynom> openShuffleTable;
    openShuffleTable.insert("Pol_1", polynom1);
    openShuffleTable.insert("Pol_2", polynom2);
    openShuffleTable.insert("Pol_3", polynom3);
    openShuffleTable.print();
    cout << endl;

    openShuffleTable.remove("Pol_2");
    openShuffleTable.print();
    cout << endl;

    openShuffleTable.remove("Pol_10");
    cout << endl << endl;

    SortedArrayTable<std::string, Polynom> sortedArrayTable;
    sortedArrayTable.insert("Pol_1", polynom1);
    sortedArrayTable.insert("Pol_2", polynom2);
    sortedArrayTable.insert("Pol_3", polynom3);
    sortedArrayTable.print();
    cout << endl;

    sortedArrayTable.remove("Pol_2");
    sortedArrayTable.print();
    cout << endl;

    sortedArrayTable.remove("Pol_10");
    cout << endl << endl;

    LinearArrayTable<std::string, Polynom> linearArrayTable;
    linearArrayTable.insert("Pol_1", polynom1);
    linearArrayTable.insert("Pol_2", polynom2);
    linearArrayTable.insert("Pol_3", polynom3);
    linearArrayTable.print();
    cout << endl;

    linearArrayTable.remove("Pol_2");
    linearArrayTable.print();
    cout << endl;

    linearArrayTable.remove("Pol_10");
    cout << endl << endl;

    LinearListTable<std::string, Polynom> linearListTable;
    linearListTable.insert("Pol_1", polynom1);
    linearListTable.insert("Pol_2", polynom2);
    linearListTable.insert("Pol_3", polynom3);
    linearListTable.print();
    cout << endl;

    linearListTable.remove("Pol_2");
    linearListTable.print();
    cout << endl;

    linearListTable.remove("Pol_10");
    cout << endl << endl;

    AVLTreeTable<std::string, Polynom> avlTreeTable;
    avlTreeTable.insert("Pol_1", polynom1);
    avlTreeTable.insert("Pol_2", polynom2);
    avlTreeTable.insert("Pol_3", polynom3);
    avlTreeTable.print();
    cout << endl;

    avlTreeTable.remove("Pol_2");
    avlTreeTable.print();
    cout << endl;

    avlTreeTable.remove("Pol_10");

	return 0;
}
