//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 15..
//  Copyright © 2017년 Zedd. All rights reserved.
//

#include<iostream>
#include<cstring>
using namespace std;
int n,maxx,t;
int arr[100001];
int dp[100001];
int func(int pos){
    if (pos==n)
        return dp[n] = arr[n];
    int &ret = dp[pos];
    maxx = func(pos+1);
    ret = max(arr[pos],arr[pos] + dp[pos+1]);
    maxx= max(maxx,ret);
    return maxx;
    
}
int main()
{
    
    cin>>t;
    while (t--) {
        memset(dp,0,sizeof(dp));
        memset(arr,0,sizeof(arr));
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        cout<<func(1)<<endl;
    }
}
