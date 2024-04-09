//Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
#include <bits\stdc++.h>
using namespace std;
int nCr(int n, int r){
  long long res=1;
  for(int i=0; i<r; i++){
    res*=(n-i);
    res/=(i+1);
  }
  return res;
}
int pascalTriangle(int r, int c){
  int element=nCr(r-1,c-1);
  return element;

}
int main(){
  int r=5, c=3, element=pascalTriangle(r,c);
  cout<<"The element at position (r,c) is: "<<element<<"n";
  return 0;
}