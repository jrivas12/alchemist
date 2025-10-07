#include <iostream>
#include <vector>

int main() {
    int N = 10;
    std::vector<int> numbers(N);

    for (int i = 0; i < N; ++i) numbers[i] = i * i;
    for (int v : numbers) std::cout << v << '\n';

    return 0;
}
