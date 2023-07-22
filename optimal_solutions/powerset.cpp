// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
   string str = "abc";
   //string with length n has 2 power n subsequences
   //print all subsets/subsequences of string str
   int n = str.size();

   for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += str[i];
			}
		}
		cout<<num<<" : "<<sub<<endl;
	}
    return 0;
}
