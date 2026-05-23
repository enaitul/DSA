#include <iostream>
using namespace std;

int main() {
    int weight;
    cin >> weight;
    
    // Check if the weight is even and greater than 2
    if (weight > 2 && weight % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
