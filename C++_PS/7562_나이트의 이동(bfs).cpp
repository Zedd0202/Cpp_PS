//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 15..
//  Copyright © 2017년 Zedd. All rights reserved.
//
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
queue<pair<int, int > > q;
int discovery[301][301];
int arr[301][301];
int l,t;
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int row,col;
int cnt;
int desrow,descol;
bool isPossible(int y, int x){
    if(y>=l||y<0||x>=l||x<0) return false;
    return true;
    
    
}
void bfs(int y, int x){
    discovery[y][x] = true;
    q.push({y,x});
    while(int s = q.size()){
        while(s--){
            int currentx = q.front().second;
            int currenty = q.front().first;
            if (currentx == descol && currenty == desrow)
                return;
            q.pop();
            for(int i=0;i<8;i++){
                int nextx = currentx + dx[i];
                int nexty = currenty + dy[i];
                if (isPossible(nexty, nextx)){
                    if(!discovery[nexty][nextx]){
                        discovery[nexty][nextx] = true;
                        q.push({nexty, nextx});
                    }
                }
            }
        }
        cnt++;
    }
    
}
int main()
{
    cin>>t;
    while(t--){
        while(!q.empty()){
            q.pop();
        }
        cnt = 0;
        memset(discovery,0,sizeof(discovery));
        cin>>l;
        cin>>row>>col;
        cin>>desrow>>descol;
        bfs(row,col);
        cout<<cnt<<endl;
       
    }
}
