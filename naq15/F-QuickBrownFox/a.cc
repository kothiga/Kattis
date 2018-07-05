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

      const int MAX = 26;
      bool letters[MAX];
      for (int i = 0; i < MAX; i++) {
	 letters[i] = false;
      }

      
      string input;
      while (ss >> input) {

	 int len = input.length();
	 for (int i = 0; i < len; i++) {

	    int val = int(tolower(input[i]) - 'a');

	    if (val >= 0) {
	       letters[val] = true;
	    }

	 }
      }

      bool broke = false;
      for (int i = 0; i < MAX; i++) {
	 if (!letters[i]) {
	    broke = true;
	    break;
	 }
      }

      if (!broke) {
	 cout << "pangram\n";
      } else {

	 cout << "missing ";
	 for (int i = 0; i < MAX; i++) {
	    if (!letters[i]) {
	       cout << char(i+'a');
	    }
	 }
	 cout << endl;
      }
   }
   
   return 0;
}
