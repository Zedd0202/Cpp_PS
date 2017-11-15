//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 15..
//  Copyright © 2017년 Zedd. All rights reserved.
//
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int row,col,k;
int arr[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int discovery[100][100];
vector<int> v;

int cnt;
int sol;
queue<pair<int, int> > q;
bool isPossible(int y, int x){
    if(y>=row||y<0||x>=col||x<0) return false;
    return true;
}
void bfs(int y, int x){
    cnt=0;
    discovery[y][x] = true;
    q.push({y,x});
    while(int s =q.size()){
        while(s--){
            int currentx = q.front().second;
            int currenty = q.front().first;
            q.pop();
            cnt++;
            for(int i=0;i<4;i++){
                int nextx = currentx +dx[i];
                int nexty = currenty +dy[i];
                if (isPossible(nexty, nextx)){
                    if(!discovery[nexty][nextx] && arr[nexty][nextx]==0){
                        discovery[nexty][nextx] =true;
                        q.push({nexty,nextx});
                    }
                }
            }
        }
       
    }
    sol++;
    
}
int main()
{
    int x1,y1,x2,y2;
    cin>>row>>col>>k;
    for(int i=0;i<k;i++){
        cin>>x1>>y1>>x2>>y2;
        for(int j=y1;j<y2;j++){
            for(int k=x1;k<x2;k++){
                arr[j][k] = 1;
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!discovery[i][j] && arr[i][j] ==0){
                bfs(i,j);
                v.push_back(cnt);
            }
        }
    }
    cout<<sol<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
