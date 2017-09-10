/*
  Solution for NAQ2015 problem f
  https://open.kattis.com/problems/quickbrownfox

     Compile : g++11 -std=c++11 -o f f.cc -Wall
  Written by : Austin Kothig
    Semester : FALL 2017
     Problem : given a phrase, print all missing letters
*/


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

   bool sol[26];
   
   int N;
   cin >> N; cin.ignore();
   while (N--) {

      // set seen to be false
      for (int i = 0; i < 26; i++)
	 sol[i] = false;

      // get the input
      string str;
      getline(cin,str);
      istringstream ss(str);

      char c;
      while (ss >> c) {
	 if (isalpha(c)) {
	    sol[tolower(c) - 'a'] = true;
	 }
      }

      // output
      bool printed = false;
      for (int i = 0; i < 26; i++) {
	 if (!sol[i]) {
	    if (!printed) { cout << "missing "; printed = true; }
	    c = 'a' + i;
	    cout << c;
	 }
      }

      if (!printed) { cout << "pangram"; }

      cout << endl;      
   }           
}
   
