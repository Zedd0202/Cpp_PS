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

string arr[100];
int discovery[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int row,col;
queue<pair<int, int> > q;
int cnt;
bool isPossible(int y, int x){
    if(y>=row||y<0||x>=col||x<0)return false;
    return true;
}
void bfs(int y, int x){
    discovery[y][x] = true;
    q.push({y,x});
    while(int s =q.size()){
        while(s--){
            int currentx = q.front().second;
            int currenty = q.front().first;
            if (currenty == row-1 && currentx == col-1)
                return;
            q.pop();
            for(int i=0;i<4;i++){
                int nextx = currentx +dx[i];
                int nexty = currenty +dy[i];
                if(isPossible(nexty, nextx)){
                    if(!discovery[nexty][nextx] && arr[nexty][nextx]=='1'){
                        discovery[nexty][nextx] = true;
                        q.push({nexty,nextx});
                        

                    }
                }
            }
        }
        cnt ++;
    }
}
int main()
{
    cin>>row>>col;
    for(int i=0;i<row;i++)
        cin>>arr[i];
    bfs(0,0);
    cout<<cnt+1;
 
}
