//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 15..
//  Copyright © 2017년 Zedd. All rights reserved.
//

#include<iostream>
#include<queue>
using namespace std;
int discovery[1000];
int n,m;
int a,b;
int arr[1000][1000];
int cnt;
queue<int > q;

void bfs(int v){
    discovery[v] = true;
    q.push(v);
    while(int s = q.size()){
        while (s--) {
            q.pop();
            for(int i=1;i<=n;i++){
                if(!discovery[i] && arr[v][i]==1){
                    bfs(i);
                }
            }
        }
        
    }
    

}





int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arr[a][b] = arr[b][a] = 1;
    }
    
    for(int i=1;i<=n;i++){
        if(!discovery[i])
        {
            bfs(i);
            cnt++;
        }
        
    }
    cout<<cnt;
    
}
