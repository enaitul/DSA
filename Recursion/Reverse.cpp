#include <bits/stdc++.h>
using namespace std;

void reverse (int i, int arr[], int n){
    if (i >= n/2) return;
    swap (arr[i], arr[n-i-1]);
    reverse (i+1, arr, n);
}

int main(){
    int arr[5] = {1, 2, 5, 6, 7};
    for (int j=0; j<5; j++){
        cout<<arr[j]<<" ";
    }
    cout<<"\n";
    reverse(0, arr, 5);
    for (int j=0; j<5; j++){
        cout<<arr[j]<< " ";
    }
    return 0;
}
