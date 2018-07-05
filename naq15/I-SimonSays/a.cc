#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {

   int n;
   cin >> n; cin.ignore();

   while (n--) {

      string s;
      getline(cin, s);

      istringstream ss(s);

      string s1, s2, s3;
      ss >> s1 >> s2;

      if (s1 == "Simon" && s2 == "says") {

	 while (ss >> s3) {
	    cout << s3 << " ";
	 }

	 cout << endl;
      }
      
   }
   
   return 0;
}
