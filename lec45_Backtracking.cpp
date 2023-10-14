//Backtracking:It is an algorithmic technique for solving recursive problems by tring to build every possible solution incrementally and removing those solutions that fail to satisfy the constraints of the problem at any point of time.
//RAT IN A MAZE

#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
  if(x<n && y<n && arr[x][y]==1){
    return true;
  }
  return false;
}

bool ratinMaze(int** arr, int x, int y, int n, int** solArr){
  
  if(x==n-1 && y==n-1){
    solArr[x][y]=1;
    return true;
  }
  
  if(isSafe(arr,x,y,n)){
    solArr[x][y]=1;
    if(ratinMaze(arr,x+1,y,n,solArr)){
      return true;
    }
    if(ratinMaze(arr,x,y+1,n,solArr)){
      return true;
    }
    solArr[x][y]=0; //Backtracking
    return false;
  }
  return false;
}

int main(){
  int n;
  cin>>n;
  
  int** arr=new int*[n];
  for(int i=0; i<n;i++){
    arr[i]=new int [n];
  }

  for(int i=0; i<n;i++){
    for(int j=0; j<n; j++){
      cin>>arr[i][j];
    }
  }

  int** solArr=new int*[n];
  for(int i=0; i<n;i++){
    solArr[i]=new int [n];
    for(int j=0; j<n;j++){
      solArr[i][j]=0;
    }
  }

  if(ratinMaze(arr,0,0,n,solArr)){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cout<<solArr[i][j]<<" ";
      }cout<<endl;
    }
  }
  return 0;
}

/*
Problem given:
1 0 1 0 1
1 1 1 1 1 
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1 
*/

