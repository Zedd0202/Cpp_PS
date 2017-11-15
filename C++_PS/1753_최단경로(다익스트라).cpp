//
//  main.cpp
//  C++_PS
//
//  Created by Zedd on 2017. 11. 15..
//  Copyright © 2017년 Zedd. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define INF 987654321

int v,e;
int src;
int start, endd, value;
vector<int> sol;
vector<pair<int, int > > graph[20001];
priority_queue<pair<int, int > > pq;
void di(int source){
    pq.push({0,source});
    sol[source]=0;
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(sol[here]<cost) continue;
        for(int i=0;i<graph[here].size();i++){
            int next = graph[here][i].first;
            int nextValue = cost+ graph[here][i].second;
            if (sol[next] > nextValue){
                sol[next] = nextValue;
                pq.push({-nextValue,next});
            }
        }
    }
}
int main()
{
    cin>>v>>e>>src;
    sol.resize(v+1,INF);
    for(int i=0;i<e;i++){
        cin>>start>>endd>>value;
        graph[start].push_back({endd,value});
    }
    di(src);
    for(int i=1;i<=v;i++){
        if(sol[i] == INF) puts("INF");
        else cout<<sol[i]<<endl;
    }
}

