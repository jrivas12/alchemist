#include <stdio.h>


//      int *radius[5];
//      for(int i = 0; i < 5, i++){
//              arr[i] = NULL;
//      for(int i = 0; i < 5, i++){
//              arr[i] = radius();
//              //lf for double
//      %d for int


double circumference(double r);
double area(double r);
double volume(double r);

const double PI = 3.14159;

int main (){

        double r;
        int choice;
        double (*arrRadius[3])(double r) = {circumstance, area, volume);
      
do{
	printf      
    
    //for("Enter radius: \n")
    //int r[3]
    //int i;
    
    //for (i = 0, i <= 3; i++){
}

        double ("func[3])(double) ={circumference, area, volume};
    while
        printf("1: Display circumference of circle.\n");
        printf("2: Display area of a circle\n");
        printf("3: Display volume of a sphere\n");
        printf("4: Exit\n");
        scanf("%d", &choice);

        if(choice>=1 && choice <=3){
//initialization
        printf("\nEnter radius:");
        scanf("%d", &r);
        printf("Calculation of option %d is: %lf\n", arrRadius[choice-1](r));
        
//option1
	  circumstance = 2 * PI * radius;
        printf("\nCalculate circumference:);
        scanf("%.2f", &circumference);
        
//option2
        area = PI * radius * radius;
        printf("\nThe area of a cirlce is:");
        scanf("%.2f", &area)
        
//option3
        volume = 4.0/3.0 * PI * radius * radius;
        printf("\nEnter radius of a sphere:");
        scanf("%lf", 4 * &radius * &radius * 2);
//option4
		while(choice! = 4);
        }

return 0;
}