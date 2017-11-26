//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 26..
//  Copyright © 2017년 Zedd. All rights reserved.
//

#include<iostream>
#include<vector>

using namespace  std;
long long cnt = 0;
vector<int> v;
vector<int> sorts(vector<int> &a) {
    vector<int> less, greater;
    if (a.size() <= 1) return a;
    int pivot = a[(a.size()-1)/2];
    int n = a.size();
    for (int i=0; i<n; i++) {
        cnt += 1;
        if (a[i] < pivot) {
            less.push_back(a[i]);
        } else if (a[i] > pivot) {
            greater.push_back(a[i]);
        }
    }
    sorts(less); sorts(greater);
    vector<int> ans;
    ans.insert(ans.end(), less.begin(), less.end());
    ans.push_back(pivot);
    ans.insert(ans.end(), greater.begin(), greater.end());
    return ans;
}
int main(){
    int a,b;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b;
        v.push_back(b);
    }
    sorts(v);
    cout<<cnt;
}
