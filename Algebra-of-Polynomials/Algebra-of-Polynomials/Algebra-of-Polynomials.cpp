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
#include "Parser.cpp"

ChainMethodTable<std::string, Polynom> chainTable;
OpenShuffleTable<std::string, Polynom> openShuffleTable;
SortedArrayTable<std::string, Polynom> sortedArrayTable;
LinearArrayTable<std::string, Polynom> linearArrayTable;
LinearListTable<std::string, Polynom> linearListTable;
AVLTreeTable<std::string, Polynom> avlTreeTable;


std::string enterName() {
    std::string key;
    std::cout << "\nEnter the name of the polynomial\n";
    std::cout << ">> ";
    std::cin >> key;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return key;
}

void addPolynomial() {
    std::string pol;

    std::cout << "\nAdding a non-existent polynomial to tables\n";
    std::cout << "Enter a new polynomial\n";
    std::cout << ">> ";

    std::getline(std::cin, pol);

    Polynom polynom = Polynom(pol);

    std::string key = enterName();

    chainTable.insert(key, polynom);
    openShuffleTable.insert(key, polynom);
    sortedArrayTable.insert(key, polynom);
    linearArrayTable.insert(key, polynom);
    linearListTable.insert(key, polynom);
    avlTreeTable.insert(key, polynom);

    std::cout << std::endl << key << " = " << polynom.toString() << " added to all tables" << std::endl;
}

void createAndAddPolynomial() {
    std::cout << "\nCreating a new polynomial from existing ones and constants, adding it to tables\n";
    std::string input;
    getline(std::cin, input);
    Parser parser(input, &sortedArrayTable);
    parser.toPostfix(input);
    Polynom tmp = parser.calculate();
    std::cout << tmp.toString() << std::endl;
}

void deletePolynomial() {
    std::string key;
    std::cout << "\nRemoving a polynomial from all tables\n";
    key = enterName();

    try {
        chainTable.remove(key);
        openShuffleTable.remove(key);
        sortedArrayTable.remove(key);
        linearArrayTable.remove(key);
        linearListTable.remove(key);
        avlTreeTable.remove(key);

        std::cout << "Polynom successfully removed from all tables\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error:" << ex.what() << std::endl;
    }
}

int menuForTables() {
    int choice;
    std::cout << "\n1. Display the entire table\n";
    std::cout << "2. Find polynomial by key\n";
    std::cout << "0. Come back\n";
    std::cout << ">> ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

void selectTable() {
    std::string key;
    int choice1, choice2;
    do {
        std::cout << "\nSelect table:\n";
        std::cout << "1. ChainMethodTable\n";
        std::cout << "2. OpenShuffleTable\n";
        std::cout << "3. SortedArrayTable\n";
        std::cout << "4. LinearArrayTable\n";
        std::cout << "5. LinearListTable\n";
        std::cout << "6. AVLTreeTable\n";
        std::cout << "0. Come back\n";
        std::cout << ">> ";
        std::cin >> choice1;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice1) {
        case 1:
            do {
                std::cout << "\nYou choosed ChainMethodTable\n";
                choice2 = menuForTables();
                switch (choice2)
                {
                case 1:
                    std::cout << std::endl;
                    chainTable.print();
                    break;
                case 2:
                    key = enterName();
                    std::cout << std::endl << key << " = " << chainTable.find(key).toString() << std::endl;
                    break;
                case 0:
                    std::cout << "Come back\n";
                    break;
                default:
                    std::cout << "Error: invalid action selection\n";
                    break;
                }
            } while (choice2 != 0);
            break;
        case 2:
            do {
                std::cout << "\nYou choosed OpenShuffleTable\n";
                choice2 = menuForTables();
                switch (choice2)
                {
                case 1:
                    std::cout << std::endl;
                    openShuffleTable.print();
                    break;
                case 2:
                    key = enterName();
                    std::cout << std::endl << key << " = " << openShuffleTable.find(key).toString() << std::endl;
                    break;
                case 0:
                    std::cout << "Come back\n";
                    break;
                default:
                    std::cout << "Error: invalid action selection\n";
                    break;
                }
            } while (choice2 != 0);
            break;
        case 3:
            do {
                std::cout << "\nYou choosed SortedArrayTable\n";
                choice2 = menuForTables();
                switch (choice2)
                {
                case 1:
                    std::cout << std::endl;
                    sortedArrayTable.print();
                    break;
                case 2:
                    key = enterName();
                    std::cout << std::endl << key << " = " << sortedArrayTable.find(key).toString() << std::endl;
                    break;
                case 0:
                    std::cout << "Come back\n";
                    break;
                default:
                    std::cout << "Error: invalid action selection\n";
                    break;
                }
            } while (choice2 != 0);
            break;
        case 4:
            do {
                std::cout << "\nYou choosed LinearArrayTable\n";
                choice2 = menuForTables();
                switch (choice2)
                {
                case 1:
                    std::cout << std::endl;
                    linearArrayTable.print();
                    break;
                case 2:
                    key = enterName();
                    std::cout << std::endl << key << " = " << linearArrayTable.find(key).toString() << std::endl;
                    break;
                case 0:
                    std::cout << "Come back\n";
                    break;
                default:
                    std::cout << "Error: invalid action selection\n";
                    break;
                }
            } while (choice2 != 0);
            break;
        case 5:
            do {
                std::cout << "\nYou choosed LinearListTable\n";
                choice2 = menuForTables();
                switch (choice2)
                {
                case 1:
                    std::cout << std::endl;
                    linearListTable.print();
                    break;
                case 2:
                    key = enterName();
                    std::cout << std::endl << key << " = " << linearListTable.find(key).toString() << std::endl;
                    break;
                case 0:
                    std::cout << "Come back\n";
                    break;
                default:
                    std::cout << "Error: invalid action selection\n";
                    break;
                }
            } while (choice2 != 0);
            break;
        case 6:
            do {
                std::cout << "\nYou choosed AVLTreeTable\n";
                choice2 = menuForTables();
                switch (choice2)
                {
                case 1:
                    std::cout << std::endl;
                    avlTreeTable.print();
                    break;
                case 2:
                    key = enterName();
                    std::cout << std::endl << key << " = " << avlTreeTable.find(key).toString() << std::endl;
                    break;
                case 0:
                    std::cout << "Come back\n";
                    break;
                default:
                    std::cout << "Error: invalid action selection\n";
                    break;
                }
            } while (choice2 != 0);
            break;
        case 0:
            std::cout << "Come back\n";
            break;
        default:
            std::cout << "Error: invalid table selection\n";
            break;
        }
    } while (choice1 != 0);
}

void performPolynomialOperations() {
    std::string key;
    int choice;
    double x, y, z, tmpConst;
    do
    {
        std::cout << "\nPerforming operations on a polynomial\n";
        std::cout << std::endl;
        sortedArrayTable.print();
        key = enterName();
        Polynom polynom = sortedArrayTable.find(key);
        std::cout << "\nChoose an action:\n";
        std::cout << "1. Calculate the value of a polynomial at a point\n";
        std::cout << "2. Multiply a polynomial by a constant\n";
        std::cout << "0. Come back\n";
        std::cout << ">> ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice)
        {
        case 1:
            std::cout << "\nEnter X\n";
            std::cout << ">> ";
            std::cin >> x;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter Y\n";
            std::cout << ">> ";
            std::cin >> y;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter Z\n";
            std::cout << ">> ";
            std::cin >> z;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl << key << " at ( " << x << ", " << y << ", " << z << " ) = " << polynom.evaluate(x, y, z) << std::endl;
            break;
        case 2:
            std::cout << "\nEnter CONST\n";
            std::cout << ">> ";
            std::cin >> tmpConst;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl << key << " * " << tmpConst << " = " << (polynom * tmpConst).toString() << std::endl;
            break;
        case 0:
            std::cout << "Come back\n";
            break;
        default:
            std::cout << "Error: invalid action selection\n";
            break;
        }
    } while (choice != 0);
}

void showMainMenu() {
    std::cout << "Choose an action:\n";
    std::cout << "1. Add non-existent polynomial to tables\n";
    std::cout << "2. Create a new polynomial from existing ones and constants, add it to tables\n";
    std::cout << "3. Remove polynomial from all tables\n";
    std::cout << "4. Select a table\n";
    std::cout << "5. Perform operations on the polynomial\n";
    std::cout << "0. Exit\n";
    std::cout << ">> ";
}

int main()
{
    int choice;
    do {
        showMainMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            addPolynomial();
            break;
        case 2:
            createAndAddPolynomial();
            break;
        case 3:
            deletePolynomial();
            break;
        case 4:
            selectTable();
            break;
        case 5:
            performPolynomialOperations();
            break;
        case 0:
            std::cout << "Exit\n";
            break;
        default:
            std::cout << "Error: invalid action selection\n";
            break;
        }
        std::cout << std::endl;

    } while (choice != 0);

	return 0;
}