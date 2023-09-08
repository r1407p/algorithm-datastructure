#include <bits/stdc++.h>

using namespace std;
struct node{
    int left;
    int right;
    int value;
};
vector<node> segment_tree;
void build(int left,int right,int index ,vector<int> & nums){
    segment_tree[index].left = left;
    segment_tree[index].right = right;
    // cout <<left <<" "<<right<<" "<<index<<endl;
    if(left == right){ // here is leaf
        segment_tree[index].value = nums[left];
        return;
    }
    int mid = (left+right)/2;
    build(left,mid,index<<1,nums);
    build(mid+1,right,index<<1|1,nums);
    segment_tree[index].value = segment_tree[index<<1].value+segment_tree[index<<1|1].value;
}
void modify(int position ,int index,int value){
    if(segment_tree[index].left == position && segment_tree[index].right ==position){ // here is leaf
        segment_tree[index].value = value;
        return;
    }
    int mid = (segment_tree[index].left+segment_tree[index].right)/2;
    
    if(position<=mid){
        modify(position,index<<1,value);
    }else{
        modify(position,index<<1|1,value);
    }
    segment_tree[index].value = segment_tree[index<<1].value,segment_tree[index<<1|1].value;
}
int query(int i,int j,int index){
    // cout <<i <<" "<<j <<" "<<segment_tree[index].left<<" " <<segment_tree[index].right<<endl;
    int res = 0;
    int left = segment_tree[index].left;
    int right = segment_tree[index].right;
    int mid = (left+right)/2;
    if(segment_tree[index].left==i && segment_tree[index].right ==j){
        
        return segment_tree[index].value;
    }
    if(i>mid)return query(i,j,index*2+1);
    if(mid>=j)return query(i,j,index*2);
    return query(i,mid,index*2)+ query(mid+1,j,index*2+1);
}
int main(){
    vector<int> nums = {1,10,5,148,78,2,56,231,5,64,65,32,1,8};
    int n  = nums.size();
    segment_tree.resize(n*4);
    build(0,n-1,1,nums);
    modify(5,1,100);//index always be 1
    // cout << "++++++++++\n";
    for(int i =0;i<n;i++){
        for(int j = i ;j<n;j++){
            cout << query(i,j,1)<<" ";//index always be 1
        }cout << endl;
    }
}