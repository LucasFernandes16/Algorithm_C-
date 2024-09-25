#include <bits/stdc++.h>
using namespace std;

int control_x[4] = {1, -1, 0, 0};
int control_y[4] = {0 ,0, 1 ,-1};

bool backtrack(int n, int m, vector<vector<char>>& maze, int start_row, int start_col, int j, int cnt){
  if(start_row < 1 or start_row >= n && j < 1 or j > m or cnt > j){
    return false;
  }
  if (maze[start_row][start_col == 'x']){
    return (cnt == j);
  }
  char temp = maze[start_row][start_col];
  maze[start_row][start_col] = '#';

  for(int step = 0; step < 4; step++){
    int next_r = start_row + control_x[step];
    int next_c = start_col + control_y[step];

    if (backtrack(n,m,maze,next_r, next_c,j,cnt)){
      return true;
    }
  }
  maze[start_row][start_col] = temp;
  return false;

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
  if(backtrack(n,m,maze,start_row,start_col,j,0)){
    cout << "SUCESS";
  }else{
    cout << "IMPOSSIBLE";
  }
}