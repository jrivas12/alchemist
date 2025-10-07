#include<iostream> 

#define PI 3.1416 

using namespace std; 



int main() { 

  int choice;

  int r, c, a, d; 

  //do{ 

    while(5){

   

   // while (choice >= 1 ||choice <= 5){

    cout << "1. Enter radius: \n";

    cout << "2. Calculate circumference\n";

    cout << "3. Calculate area \n";

    cout << "4. Calculate diameter\n";

    cout << "5. Exit \n";

    cin>>choice; 

    switch (choice) { 

      case 1: 

        cout << "Enter the radius of circle: "; 

        cin >> r; 

        cout << "The radius of circle is: "<< r << endl; 

        break;  

      case 2: 

        cout << "Enter the radius of circle: "; 

        cin >> r; 

        cout << "Circumference of circle: "

           << 2*PI*r 

           << endl; 

           break;

      case 3:

        cout << "Enter radius of circle: ";

        cin >> r;

        cout << "Area of circle is: "<< PI*r*r << endl; 

        break;

      case 4:

        cout << "Enter radius of circle: ";

        cin >> r;

        cout << "The diameter of the circle is:" 

           << r+r 

           << endl;

        break;

      default: 

        cout << "invalid selection (5 to exit!)\n"; 

        break; 

      }

    }while(choice!=5)

     

    return 0;

   

}

   