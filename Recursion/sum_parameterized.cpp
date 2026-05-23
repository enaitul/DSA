#include <bits/stdc++.h>
using namespace std;

void func(int i, int sum){
    if (i<0){
        cout<< "The sum is: "<< sum;
        return;
    }
    func (i - 1, sum + i);
}

int main(){
    func (3,0);
    return 0;
}