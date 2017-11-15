//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 15..
//  Copyright © 2017년 Zedd. All rights reserved.
//



//주의 : 처음 주어지는 토마토의 개수가 하나가 아니므로, 1이면 먼저 queue에 넣고 시작해야함!!!!
#include<iostream>
#include<queue>
using namespace std;
int row, col;
int arr[1001][1001];
int discovery[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int cnt;
int check;
int sol;
queue<pair<int, int > > q;
bool isPossible(int y, int x){
    if(y>=row||y<0||x>=col||x<0) return false;
    return true;
}
void bfs(){
    while(int s= q.size()){
        while(s--){
            int currentx = q.front().second;
            int currenty = q.front().first;
            q.pop();
            for(int i=0;i<4;i++){
                int nextx = currentx +dx[i];
                int nexty = currenty +dy[i];
                if(isPossible(nexty, nextx)) {
                    if(arr[nexty][nextx] == 0){
                        arr[nexty][nextx] = 1;
                        sol--;
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
    cin>>col>>row;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
            cin>>arr[i][j];
            if (arr[i][j]==1){
                check++;
                q.push({i,j});
            }
            else if (arr[i][j]==0){
                sol++;
            }
        }
    }
    bfs();
    if (sol!=0){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<cnt-1<<endl;
}
