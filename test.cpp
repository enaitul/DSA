#include <bits/stdc++.h>
using namespace std;

void print_int(int n){

    if (n == 0 ) return;
    cout<<n<<endl;
   
    print_int(n-1);

}

int main() {
    print_int(5);
    return 0;
}