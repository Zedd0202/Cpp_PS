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
queue<pair<int,int> > q;
int row,col;
int arr[51][51];
int discovery[51][51];
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};
int cnt;
bool isPossible(int y, int x){
    if (y>=row|| y<0|| x>=col|| x<0) return false;
    return true;
}
void bfs(int y, int x){
    discovery[y][x] = true;
    q.push({y,x});
    while(int s = q.size()){
        while(s--){
            int currentx = q.front().second;
            int currenty = q.front().first;
            q.pop();
            for(int i=0;i<8;i++){
                int nextx = currentx+dx[i];
                int nexty = currenty+dy[i];
                if (isPossible(nexty, nextx)){
                    if(!discovery[nexty][nextx] && arr[nexty][nextx]==1){
                        discovery[nexty][nextx] = true;
                        q.push({nexty,nextx});
                    }
                }
            }
            
        }
        
    }
    
}
int main()
{
    while(cin>>col>>row){
        cnt = 0;
        memset(discovery,0, sizeof(discovery));
        memset(arr,0,sizeof(arr));
        if (col == 0 && row ==0)
            return 0;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cin>>arr[i][j];
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(!discovery[i][j] && arr[i][j] == 1){
                    bfs(i,j);
                    cnt++;
                }
            }
        cout<<cnt<<endl;
    }
  
}
