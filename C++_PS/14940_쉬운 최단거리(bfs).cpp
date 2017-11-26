//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 20..
//  Copyright © 2017년 Zedd. All rights reserved.
//
#include<iostream>
#include<queue>
using namespace std;
int row,col;
int arr[1001][1001];
int discovery[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int sol[1001][1001];
int startRow, startCol;
queue<pair<int, int> > q;
bool isPossible(int y,int x){
    if (y>=row||y<0||x>=col||x<0) return false;
    return true;
}
void bfs(int y, int x){
    int cnt = 0;
    discovery[y][x] = true;
    q.push({y,x});
    sol[y][x] = 0;
    cnt++;
    while(int s = q.size()){
        while(s--){
            int currenty = q.front().first;
            int currentx = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nextx = currentx+ dx[i];
                int nexty = currenty + dy[i];
                if(isPossible(nexty, nextx)){
                    if(!discovery[nexty][nextx] && arr[nexty][nextx] == 1){
                        discovery[nexty][nextx] = true;
                        sol[nexty][nextx] = cnt;
                        q.push({nexty,nextx});
                    }
                }
            }
            
        }
        cnt++;
    }
}
int main()
{
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
            if (arr[i][j] == 2){
                startRow = i;
                startCol = j;
            }
        }
    }
    bfs(startRow,startCol);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] == 0 || arr[i][j] == 2){
                cout<<"0"<<" ";
                continue;
            }
            if(arr[i][j] == 1 && discovery[i][j] )
                cout<<sol[i][j]<<" ";
            
            else if(arr[i][j]==1 && !discovery[i][j])
                cout<<"-1"<<" ";

            
            
        }
        cout<<endl;
    }
}
