//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 20..
//  Copyright © 2017년 Zedd. All rights reserved.
//

#include<iostream>
#include<cstring>
using namespace std;
int n;
long long dp[100];
long long func(int num)
{
    if (num == 0) return 0;
    if (num == 1) return 1;
    if (num == 2) return 1;
    
    long long &ret = dp[num];
    if (ret != -1) return ret;
    return ret = func(num - 1) + func(num - 2);
    
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout<<func(n);
    
}
