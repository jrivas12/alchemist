#include <iostream>
#include <vector>

int main() {
    int N = 10;
    std::vector<int> numbers(N);

    // First part: assign each element in the array a value
    for(int i = 0; i < N; i++) {
        numbers[i] = i * i;
    }

    // Second part: print each element in the array
    for(int i = 0; i < N; i++) {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
}


void doSomething( int k ); 

for(i = 0; i < N; i++)
{
   for(j = N; j > 0; j--)
   {
     doSomething( N );
   }
}

#include <iostream>
#include <vector>

// Assume that function doSomething(k) has a linear time complexity proportional to k, or O(k).
void doSomething(int k) {
    for(int i = 0; i < k; i++) {
        std::cout << i << std::endl;
    }
}

int main() {
    int N = 10;

    for(int i = 0; i < N; i++) {
        for(int j = N; j > 0; j--) {
            doSomething(N);
        }
    }

    return 0;
}

for(int i = 1; i < N; i = i * 2)

{

cout << i << endl;

}

#include <iostream>

int main() {
    int N = 32;

    for(int i = 1; i < N; i = i * 2) {
        std::cout << i << std::endl;
    }

    return 0;
}
