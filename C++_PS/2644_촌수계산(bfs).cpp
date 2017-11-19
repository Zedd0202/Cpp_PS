//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 17..
//  Copyright © 2017년 Zedd. All rights reserved.
//

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<int> q;
int n,a,b,m,c,d,cnt;
bool flag ;
vector<vector<int> > v;
int discovery[101];
void bfs(int pos){
    discovery[pos] = true;
    q.push(pos);
    while(int s = q.size()){
        while(s--){
            int currentV =  q.front();
            q.pop();
            
            if (currentV == b){
                flag = true;
                return;
            }
            for(int i=0;i<v[currentV].size();i++){
                int next = v[currentV][i];
                if(!discovery[next]){
                    discovery[next] = true;
                    q.push(next);
                }
            }
            
        }
        cnt++;
    }
}
int main()
{
    cin>>n>>a>>b>>m;
    v.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>c>>d;
        v[c].push_back(d);
        v[d].push_back(c);
    }
    bfs(a);
    if(flag) cout<<cnt;
    else cout<<"-1";
 
}
