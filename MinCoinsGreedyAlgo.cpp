#include <bits/stdc++.h>
using namespace std;

int main(){
    int deno[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    int v;
    cout<< "Enter the value: ";
    cin>> v;
    vector<int> ans;

    for (int i = n-1; i >= 0; i--){
        if (v > deno[i]){
            ans.push_back(deno[i]);
            v -= deno[i];
        }
    }
    cout << "The coin combination is :  ";
    for (int i = 0; i<ans.size(); i++){
        cout<< ans[i] << "  ";
    }
    
    return 0;
}