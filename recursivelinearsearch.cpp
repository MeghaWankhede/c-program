#include <iostream>

// Recursive linear search
int recursiveLinearSearch(int arr[], int key, int size, int index) {
    if (index == size) {
        return -1; // Key not found in the array
    }
    if (arr[index] == key) {
        return index; // Key found at this index
    }
    return recursiveLinearSearch(arr, key, size, index + 1); // Recursively search the rest of the array
}

// Non-recursive (iterative) linear search
int iterativeLinearSearch(int arr[], int key, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Key found at this index
        }
    }
    return -1; // Key not found in the array
}

int main() {
    int arr[] = {12, 34, 45, 21, 54, 9, 81};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 54;

    // Recursive linear search
    int recursiveResult = recursiveLinearSearch(arr, key, size, 0);
    if (recursiveResult != -1) {
        std::cout << "Key " << key << " found at index (recursive): " << recursiveResult << std::endl;
    } else {
        std::cout << "Key " << key << " not found (recursive)." << std::endl;
    }

    // Non-recursive (iterative) linear search
    int iterativeResult = iterativeLinearSearch(arr, key, size);
    if (iterativeResult != -1) {
        std::cout << "Key " << key << " found at index (iterative): " << iterativeResult << std::endl;
    } else {
        std::cout << "Key " << key << " not found (iterative)." << std::endl;
    }

    return 0;
}
