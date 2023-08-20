#include<bits/stdc++.h>
using namespace std;
int n = 9;
vector<vector<int>> graph;
vector<int>tin(n,0);
vector<int>tout(n,0);
int t = 0;
void dfs(int x, int px)	// px是x的父親
{
	tin[x] = t++;

	for(auto y:graph[x]){
        if(y!=px)
            dfs(y,x);
    }
	tout[x] = t++;
}
bool x_is_ancestor_of_y(int x, int y)
{
	return tin[x] < tin[y] && tout[x] > tout[y];
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
    
    dfs(0,-1);
    int x, y;
	while (cin >> x >> y)
		if (x_is_ancestor_of_y(x, y))
			cout << "x是y的祖先";
		else if (x_is_ancestor_of_y(y, x))
			cout << "y是x的祖先";
		else
			cout << "xy不是祖孫關係";
}