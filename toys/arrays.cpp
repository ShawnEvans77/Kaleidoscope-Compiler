#include <iostream>

int find_largest(int A[], int n);

int main() {
    int A[] = {1,2,3,4,5};

    std::cout << find_largest(A, sizeof(A) / sizeof(A[0])) << '\n';

    return 0;
}

int find_largest(int A[], int n) {
    int largest = A[0];

    for (int i = 0; i < n; i++) {
        if (largest < A[i]) {
            largest = A[i];
        }
    }

    return largest;
}