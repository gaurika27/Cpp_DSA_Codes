//count the number of paths possible from start point to end point
#include <iostream>
using namespace std;

int countPath(int s, int e){
  if(s==e){
    return 1;
  }
  if(s>e){
    return 0;
  }
  int count=0;
  for(int i=1; i<=6;i++){
    count+=countPath(s=1,e);
  }
  return count;
}

int main(){
  cout<<countPath(0,3)<<endl;
  return 0;
}