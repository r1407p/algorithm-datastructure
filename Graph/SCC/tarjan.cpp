#include <bits/stdc++.h>
using namespace std;
const int n = 16;
vector<vector<int>> graph;
int visit[n], low[n],t = 0;
int st[n], top =0;
int contract[n]; // 每個點收縮到的點
vector<vector<int>> block;
void dfs(int x,int parent){
    visit[x] = low[x] = ++t;
    st[top++] = x;
    for(auto to:graph[x]){ // tree edge
        if( !visit[to]){
                dfs(to,x);
        }
        if(to!=parent){ //tree/back edge
            low[x] = min(low[x],low[to]);
        }
    }
    if(visit[x] ==low[x]){ 
        block.push_back({});
		int j;
		do {
			j = st[--top];	// pop j
            block[block.size()-1].push_back(j);
			contract[j] = x;
		} while (x != j);
    }
}
int main(){
    graph = {
        {1},
        {0,3,4,5},
        {3,6},
        {1,2,6},
        {1,7,9},
        {1,11,13,15},
        {2,3},
        {4,9,10},
        {},
        {4,7,10},
        {7,9},
        {5,15},
        {14,15},
        {5,15},
        {12,15},
        {5,11,12,13,14}
    };
    for(int i =0;i<n;i++){
        if (!visit[i])
			dfs(i, i);
    }
    for(auto t: block){
        for(auto x:t){
            cout << x <<" ";
        }cout <<endl;
    }
}