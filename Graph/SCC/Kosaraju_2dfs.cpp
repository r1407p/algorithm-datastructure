#include <bits/stdc++.h>
using namespace std;
const int n = 16;
vector<vector<int>> graph;
vector<vector<int>> reverse_graph;
int visit[n];
int contract[n]; // 每個點收縮到的點
vector<vector<int>> block;
vector<int> finish;//fake topological sort

void dfs1(int x){ 
    visit[x] = true;
    for(auto to:graph[x]){
        if(!visit[to]){
            dfs1(to);
        }
    }
    finish.push_back(x);
}
void dfs2(int x,int c){ 
    contract[x] = c;
    block[c].push_back(x);
    visit[x] = true; 
    for(auto to:reverse_graph[x]){ 
        if(!visit[to]){
            dfs2(to,c);
        }
    }  
}

int main(){
   graph = {
        {1},
        {3,4,5},
        {6},
        {2},
        {7},
        {11,15},
        {2,3},
        {4,6,9},
        {},
        {},
        {},
        {15},
        {14},
        {13,5},
        {15},
        {10,12,13}
    };
    reverse_graph = {
        {},
        {0},
        {3,6},
        {1,6},
        {1,7},
        {1,13},
        {2,7},
        {4},
        {},
        {7},
        {15},
        {5},
        {15},
        {13,15},
        {12},
        {5,11,14}
    };
     
    for(int i =0;i<n;i++){
        if (!visit[i])
			dfs1(i);
    }
    int c =0;
    memset(visit,0,sizeof(visit));
    for(int i =  n-1;i>=0;i--){
        if(!visit[finish[i]]){ 
            block.push_back({});
            dfs2(finish[i],c++);
        }
    }
    for(auto t: block){
        for(auto x:t){
            cout << x <<" ";
        }cout <<endl;
    }
}