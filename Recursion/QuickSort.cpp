#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Use last element as pivot to avoid edge cases
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

int main() {
    int a[] = {1, 4, 2, 5, 2, 8, 6};
    int n = sizeof(a) / sizeof(a[0]);
    
    vector<int> arr(a, a + n);
    
    qs(arr, 0, n - 1);
    
    for (int i : arr) {
        cout << i << " ";
    }
    
    cout << endl;
    return 0;
}
