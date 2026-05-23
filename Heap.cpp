#include <iostream>
#include <algorithm>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << ", ";
        }
    }

    void deletefromheap() {
    if (size == 0) {
        cout << "Nothing to delete" << endl;
        return;
    }

    arr[1] = arr[size]; // Move the last element to the root
    size--;
    int i = 1;

    while (i <= size) {
        int leftindex = 2 * i;
        int rightindex = 2 * i + 1;

        // Compare with left child
        if (leftindex <= size && arr[i] < arr[leftindex]) {
            swap(arr[i], arr[leftindex]);
            i = leftindex;
        }
        // Compare with right child only if left condition is not met
        else if (rightindex <= size && arr[i] < arr[rightindex]) {
            swap(arr[i], arr[rightindex]);
            i = rightindex;
        }
        else {
            break; // Break if no swaps are needed
        }
    }
}

};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    
    h.print();
    h.deletefromheap();
    cout <<endl<< "After deletion: "<< endl;
    h.print();


    return 0;
}
