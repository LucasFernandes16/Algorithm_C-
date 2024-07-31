#include <bits/stdc++.h>
using namespace std;

bool backtrack(int n, int m, vector<vector<char>>& maze, int start_row, int start_col, int j){
  if(start_row < 1 or start_row >= n && j < 1 or j > m and )

}



int main(){
  int n,m,j;
  int start_row, start_col;
  vector<vector<char>> maze;


  cin >> n >> m >> j;
  for(int i = 0; i < n; i++){
    for(int p = 0; p < j; p++){
      cin >> maze[i][j];
      if(maze[i][p] == '@'){
        start_row = i;
        start_col = p;
      }
    }
  }
}