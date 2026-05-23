#include<bits/stdc++.h>
using namespace std;

int func(int i){
    if (i <= 0){
        return 0;
    }
    return i + func(i-1);
}

int main(){
    cout << "The sum of first 3 natural numbers is: "<< func(3);
    return 0;
}