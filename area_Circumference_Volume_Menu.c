#include<stdio.h>
#include<math.h>

void circumference(double radius);
void area(double radius);
void volume(double radius);
void menu();
const double PI = 3.14159;

int main(void) {
    void (*f[3])(double) = {&circumference, &area, &volume};
    size_t choice = 0;
    double radius = 0;

    while (1) {
        menu();
        scanf("%zu", &choice);  // safer type for size_t

        if (choice >= 1 && choice <= 3) {   // ✅ allow 1, 2, and 3
            printf("\nEnter the radius: ");
            scanf("%lf", &radius);
            (*f[choice - 1])(radius);       // ✅ adjust index to 0–2
        } else if (choice == 4) {
            printf("\nGoodbye.\n");
            break;
        } else {
            printf("\n\terror: Enter valid choice!\n");
        }
        printf("\n");
    }
    return 0;
}

void menu() {
    printf("Select an option from below\n");
    printf("1. Calculate the circumference of a circle.\n");
    printf("2. Calculate the area of a circle.\n");
    printf("3. Calculate the volume of a sphere.\n");
    printf("4. Exit Program.\n");
}

void circumference(double radius) {
    printf("\nRadius = %.3f", radius);
    double circum = 2.0 * PI * radius;
    printf("\nThe circumference of the circle is %.2lf feet.\n", circum);
}

void area(double radius) {
    printf("\nRadius = %.3f", radius);
    double a = PI * radius * radius;
    printf("\nThe area of the circle is %.2lf feet squared.\n", a);
}

void volume(double radius) {
    printf("\nRadius = %.3f", radius);
    double vol = (4.0 / 3.0) * PI * radius * radius * radius;
    printf("\nThe volume of the sphere is %.2lf cubic feet.\n", vol);
}