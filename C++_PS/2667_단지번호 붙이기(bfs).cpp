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
int dx[4] = {0,1,0,-1};
int dy[4] ={1,0,-1,0};
string arr[30];
int discovery[30][30];
int n;
int cnt;
vector<int> v;
int sol;
queue<pair<int, int> > q;
bool isPossible(int y, int x){
    if(y>=n||y<0||x>=n||x<0) return false;
    return true;
}
void bfs(int y, int x){
    discovery[y][x] = true;
    cnt =0;
    q.push({y,x});
    while(int s = q.size()){
        while(s--){
            int currentx = q.front().second;
            int currenty = q.front().first;
            q.pop();
            cnt++;
            for(int i=0;i<4;i++){
                int nextx = currentx+ dx[i];
                int nexty = currenty +dy[i];
                if (isPossible(nexty, nextx)){
                    if(!discovery[nexty][nextx] && arr[nexty][nextx] == '1'){
                        discovery[nexty][nextx] = true;
                        q.push({nexty,nextx});
                    }
                }
            }
        }
    }
    v.push_back(cnt);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!discovery[i][j] && arr[i][j] == '1'){
            bfs(i,j);
            sol++;
            }
        }
    }
    cout<<sol<<endl;
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}
