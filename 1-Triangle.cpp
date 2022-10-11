#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>&a){
    if(i==0 and j==0) return a[i][j];
    if(i<0 or j<0)  return 1e9;

    int top=a[i][j] + f(i-1,j,a);
    int topLeft=a[i][j] + f(i-1,j-1,a);

    return min(top,topLeft);
}

int main(){
    vector<vector<int>>a={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<f(3,3,a)<<endl;
}