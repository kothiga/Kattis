#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int MAX = 37;
char table[MAX];
map<char, int> conv;


bool convert(int base, string val, long long& total) {

   int len = val.length();
   total = 0;

   if (base == 1) {
      for (int i = 0; i < len; i++) {
	 if (val[i] != '1') { return false; }
	 total += 1;
      }
      return true;
   }

   for (int i = 0; i < len; i++) {

      total *= base;
      total += conv[val[i]];

      if (conv[val[i]] >= base) {	 
	 return false;
      }
   }
   
   return true;
}


bool solve(int base, string X, string op, string Y, string Z) {
     
   //-- convert X, Y, and Z into base 10 from base `base`.
   long long x, y, z;
   bool x_bool = convert(base, X, x); if (!x_bool) return false;
   bool y_bool = convert(base, Y, y); if (!y_bool) return false;
   bool z_bool = convert(base, Z, z); if (!z_bool) return false;
   
   if (op == "+") {
      return (x + y) == z;
   } else if (op == "-") {
      return (x - y) == z;
   } else if (op == "*") {
      return (x * y) == z;
   } else if (op == "/") {
      return (x / y) == z && x % y == 0;
   }

   //-- should not get here.
   return false;
}


int main() {

   int n;
   cin >> n;

   for (int i = 1; i < 10; i++) {
      table[i] = char(i + '0');
      conv[table[i]] = i;
   }

   for (int i = 0; i < 26; i++) {
      table[i+10] = char(i + 'a');
      conv[table[i+10]] = i+10;
   }

   table[36] = '0';
   conv['0'] = 0;
   

   while (n--) {

      string X, op, Y, Z;
      cin >> X >> op >> Y >> Z >> Z;

      bool printed = false;
      for (int i = 1; i < MAX; i++) {
	 if (solve(i, X, op, Y, Z)) {
	    cout << table[i];
	    printed = true;
	 }
      }

      if (!printed) {
	 cout << "invalid";
      }

      cout << endl;
   }

   return 0;
}
