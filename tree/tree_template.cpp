#include<bits/stdc++.h>
using namespace std;
const int n = 9;
vector<vector<int>> graph; 
vector<int> visit(n,0);
int t = 0;
void dfs(int x,int parent){

}
int main(){
    graph = {
        {1,2},
        {3},
        {5,6},
        {7},
        {},
        {},
        {},
        {8},
        {4},
    };
    for(int i =0;i<9;i++){
        if(!visit[i])
            dfs(i,-1);
    }
}