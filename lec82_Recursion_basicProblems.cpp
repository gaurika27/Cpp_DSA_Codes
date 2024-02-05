//1)Print name N times using recursion
#include<vector>
using namespace std;
void name(i,n){
  if(i>n) return; //base case
  cout<<"Gaurika";
  name(i+1,n);
}
int main(){
  int n;
  cin>>n;
  name(0,n);

}