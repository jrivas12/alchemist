#include <iostream>
using namespace std;

int main()
{

        float accountNumber = 0;
        float beginningBal  = 0;
        float totalCharges  = 0;
        float totalCredits  = 0;
        float creditLimit   = 0;
        float newBal        = 0;

        cout << "Enter Account Number (1-100) or -1 to Quit: ";
        cin  >> accountNumber;

        while(accountNumber != -1)
        {
                cout << "Enter Beginning Balance: ";
                cin  >> beginningBal;

                cout << "Enter Total Charges: ";
                cin  >> totalCharges;

                cout << "Enter Total Credits: ";
                cin  >> totalCredits;

                cout << "Enter Credit Limit: ";
                cin  >> creditLimit;

                newBal = beginningBal + totalCharges - totalCredits;
                cout << "New Balance: " << newBal  << endl;

                if (newBal > creditLimit)
                {
                        cout << "Account Number: " << accountNumber << endl;
                        cout << "Credit Limit: "   << creditLimit   << endl;
                        cout << "Balance: "        << newBal        << endl;
                        cout << "Credit Limit Exceeded! \n\n";
                }
                cout << "Enter Account Number (1-100) or -1 Quit: ";
                cin >> accountNumber;
        }

        return 0;
}
