#include<iostream>
using namespace std;

int main(){

    int n,q;
    cin >> n >> q;

    int setOfNum[n];
    int ans[q];

    for(int i = 0; i<n ; i++)
        cin >> setOfNum[i];
    
    int minTable[n][n];

    for(int i = 0; i<n ; i++){
        minTable[i][i] = setOfNum[i];
        for(int j = i+1; j<n ; j++){
            minTable[i][j] = min(minTable[i][j-1], setOfNum[j]);
        }
    }

    for(int i = 0; i<q ; i++){
        int l,r;
        cin >> l >> r;
        ans[i] = minTable[l][r-1];
    }

    for(int i = 0; i<q ; i++){
        cout << ans[i] << endl;
    }

    

    return 0;
}