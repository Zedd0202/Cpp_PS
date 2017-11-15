//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 15..
//  Copyright © 2017년 Zedd. All rights reserved.
//

#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int origin[100001];
int newArr[100001];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&origin[i]);
    sort(origin,origin+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d",&newArr[i]);
    for(int i=0;i<m;i++){
       if (binary_search(origin, origin+n, newArr[i]))
           puts("1");
       
       else
           puts("0");
    }
}

