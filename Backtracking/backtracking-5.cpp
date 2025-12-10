// RAT IN A MAZE

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void helper(vector<vector<int>> &maze,int r,int c,string path,vector<string>&ans){
 
    int n = maze.size();

    // base case 1
    if (r<0 || c<0 || r>=n|| c >=n||maze[r][c] == 0|| maze[r][c] == -1){
        return;
    }
// 2
  if (r == n-1 && c == n-1){
    ans.push_back(path);
    return;
  }

   maze[r][c] = -1; //visited.

   helper(maze,r+1,c,path+"D",ans);
    helper(maze,r,c+1,path+"R",ans);
     helper(maze,r,c-1,path+"L",ans);
      helper(maze,r-1,c,path+"U",ans);

      // after hiting the base case.
   maze[r][c] = 1; // unvisited // backtracking step.

}

vector<string> find_path(vector<vector<int>>&maze){
 
    int n=  maze.size();
    vector<string> ans;
    
    string path = "";
    
    // PATH : track a ans part
    // ANS : STORES all correct path taking from 'path string'.

    helper(maze,0,0,path,ans);
    return ans;
    
}
int main(){

    vector<vector<int>> maze  = {{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};

    vector<string> ans = find_path(maze);

    for(string path:ans){
     
        cout<<"START -> "<< path<< " <- END" <<endl;
    }
    return 0;
}