//Bitwise operators
/*
Bitwise AND(&)         : Gets 1 only when both of the bits are 1 and otherwise we'll get 0 for 00, 01, 10
        OR(|)          : Gets 1 if there is even a single 1 i.e, gets 1 for 01,10,11 and gets 0 if theere is not even a single 1, i.e, gets 0 for 00
        XOR(^)         : Gets 1 for odd number of 1s and 0 for even number of 1s, i.e, 1 for 01, 10 and 0 for 00, 11
        Left shift(<<) : for ex: 5<<1. so binary representation of 5 is 00000101. so remove leftmost one bit(i.e, 0) and put 0 at the end,i.e, at the rightmost place i.e. 00000101 becomes 00001010 which is 10. for 5<<2: 00000101 become 00010100 which is 20.
        so, it looks like 5<<1 = 5 * (2^1) [2 raised to the power 1 and not 2 xor 1 here] 
                          5<<2 = 5 * (2^2) [2 raised to the power 2 and not 2 xor 2 here]
        so, we can conclude that a<<n = a*(2^n) [a is multiplied with 2 raised to the power n]
        
        Right shift(>>): for ex: 5>>1. so binary representation of 5 us 00000101. so remove rightmost one bit(i.e, 1) and put 0 at the end, i.e, at the leftmost place i.e, 00000010 which is binary representation of 2.                                           
        so, we can conclude that a>>n = a/(2^n) [a is divided by 2 raised to the power n]
       
        Not(~)         : flip all the bits(1's complement)
*/
//Why Bitwise operators
/*
TC of /, *: O(n^2): not desirable in cp
TC of %   : O(n^3): heavy and hence, not desirable
Also, bitwise operators are fast

*/

#include<bits\stdc++.h>
using namespace std;
int main(){
  //1)Define bitset
  bitset<2> arr;
  arr[0]=1;
  arr[1]=0;
  cout<<arr<<'\n'; //output will be 01: because in bitset it stores in reverse i.e, arr starts with n-1(leftmost) and ends at 0th index(rightmost)

  //2)Integer to bitset and vice-versa
  bitset<4> a_int(8); //make a bitset of size 4 and insert 8 in it
  cout<<a_int<<endl; // output: 1000 : this is 8 in binary and 8 is an integerso it is stored as 1000 in bitset
  int n=(int) a_int.to_ulong(); //to_ulong() is used to convert the bitset into long and then (int) is used to typecast the long into int and then it is stored into int n
  cout<<n<<endl;
  }

  //3)String to bitset
  string str="1010110100";
  bitset<10> brr(str);
  cout<<brr[0]<<endl; //output: 0
  string new_Str=brr.to_string();
  cout<<new_str<<endl;

  //4)Count number of ones
  cout<<brr.count()<<endl; //output: 5

  //5)Basic operations
  bitset<4> a(String("0101"));
  bitset<4> b(String("1010"));
  cout<<(a&b)<<endl; //0000
  cout<<(a|b)<<endl; //1111
  cout<<(a^b)<<endl; //1111
  cout<<(~a)<<endl; //1010
  cout<<(a<<1)<<endl; //1010
  cout<<(a>>1)<<endl; //0101

  //6)
  string str1="1010110100";
  istringstream stream(str1);
  bitset<2> s1;
  bitset<6> s2;
  stream >> s1;
  cout<< s1<< endl; //output:10
  stream>> s2;
  cout<< s2<<endl; //output:101101

  //7)Check if any bit is set(i.e, if any bit is 1)
  bitset<4> a1(string("1010")); 
  bitset<4> b1(string("0000"));
  cout<<a1.any()<<endl; //output: true
  cout<<b1.any()<<endl; //output: false

  //8)check if none of the  bits are set
  cout<<a1.none()<<endl; //false
  cout<<b1.none()<<endl; //true

  //9)check if all bits are set
  bitset<4> ball(String("1111"));
  cout<<ball.all()<<endl;

  //10)Flip all or any particular bit
  bitset<4> a3(string("!010"));
  cout<<a3.flip()<<endl; //0101
  cout<<a3<<endl; //0101
  cout<<a3.flip(1)<<endl; //0111

  //11)Reset all or any particular bit
  bitset<4> a4(string("!010")); 
  cout<<a4.reset(1)<<endl; //1000
  cout<<a4.reset()<<endl; //0000

  //12)Set all or any particular bit
  bitset<4> s5(string("!010"));
  cout<<a5.set(0)<<endl; //1011
  cout<<a5.set()<<endl; //0000

  return 0;