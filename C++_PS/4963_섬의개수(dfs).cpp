//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 15..
//  Copyright © 2017년 Zedd. All rights reserved.
//

#include<iostream>
using namespace std;
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};
int arr[51][51];
int visited[51][51];
int cnt;
int row,col;
bool isPossible(int y, int x){
    if (y>=row|| y<0|| x>=col|| x<0) return false;
    return true;
}
void dfs(int y,int x){
    visited[y][x] = true;
    for(int i=0;i<8;i++){
        int nextx = x+dx[i];
        int nexty = y +dy[i];
        if (isPossible(nexty, nextx)){
            if(!visited[nexty][nextx] && arr[nexty][nextx] == 1){
                dfs(nexty,nextx);
            }
        }
    }
}
int main()
{
    while(cin>>col>>row){
        cnt = 0;
        memset(visited,0, sizeof(visited));
        memset(arr,0,sizeof(arr));
        if (col == 0 && row ==0)
            return 0;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                cin>>arr[i][j];
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(!visited[i][j] && arr[i][j] == 1){
                    dfs(i,j);
                    cnt++;
                }
            }
        cout<<cnt<<endl;
    }
}
