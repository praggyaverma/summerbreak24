#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
vector<int>current;
void solve(int i,int sum,vector<int>&nums,int x ){
   
  if(i==nums.size()){
   if(sum==x){
  ans.push_back(current);
 
   }
   return;
  }
  current.push_back(nums[i]);
  solve(i+1,sum+nums[i],nums,x);
  current.pop_back();

  solve(i+1,sum,nums,x);

}
vector<vector<int>> subsets(vector<int>&nums,int k){
    ans.clear();
    current.clear();
    solve(0,0,nums,k);
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>p=subsets(nums,k);
    for(auto &sub:p){
        cout<<"{";
        for(int x:sub){
            cout<<x<<" ";
        }
        cout<<"}";
    }
    return 0;
}
