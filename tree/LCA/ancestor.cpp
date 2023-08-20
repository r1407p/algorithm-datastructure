#include<bits/stdc++.h>
using namespace std;
int n;
int logn;
vector<vector<int>> graph; 
vector<int> parent;	
vector<vector<int>>ancestor;
void dfs(int x){
	for(auto y:graph[x]){
        if(y!= parent[x]){
            parent[y] =x;
            ancestor[y][0] = x;
            dfs(y);
        }
    }
}

void table()
{
    // 上兩輩祖先、上四輩祖先、上八輩祖先、……
	for (int i=1; i<logn; i++)
		for (int x=0; x<n; ++x)
			ancestor[x][i] = ancestor[ancestor[x][i-1]][i-1];
}

int kth_ancestor(int x, int k)
{
	// k拆解成二進位位數，找到第k祖先。不斷上升逼近之。
	for (int i=0; i<logn; i++)
		if (k & (1<<i))
			x = ancestor[x][i];
	return x;
}

void rooted_tree(int root)
{
	parent[root] = root;
	dfs(root);
	table();
	int x, k;
	while (cin >> x >> k)
		if (k >= logn) 
			cout << "x點的第k祖先是" << root;
		else
			cout << "x點的第k祖先是" << kth_ancestor(x, k);
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
    n = 9;
    logn = ceil(log2(n));
    ancestor.resize(n,vector<int>(logn));
    parent.resize(n);
    rooted_tree(0);

}