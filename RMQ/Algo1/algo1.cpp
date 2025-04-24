#include<iostream>
using namespace std;

int main(){

    int n,q;
    cin >> n;

    int setOfNum[n];

    for(int i = 0; i<n ; i++)
        cin >> setOfNum[i];

    cin >> q;
    int ans[q];
    

    for(int k = 0; k<q ; k++){
        int i,j;

        cin >> i >> j;

        ans[k] = setOfNum[i];

        for(int l = i+1; l<=j; l++)
            if(setOfNum[l] < ans[k])
                ans[k] = setOfNum[l];
    }

    for(int i = 0; i<q; i++)
        cout << ans[i] << endl;

    return 0;
}