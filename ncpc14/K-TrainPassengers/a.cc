#include <iostream>

using namespace std;

int main() {

   int C, N, left, enter, stay;
   cin >> C >> N;

   bool possible = true;
   int total = 0;
   
   while (N--) {

      cin >> left >> enter >> stay;
      
      //-- did more people get off than were on the train.
      total -= left;
      if (total < 0) {
	 possible = false;
      }

      //-- did more people enter the train than it could hold.
      total += enter;
      if (total > C) {
	 possible = false;
      }
   
      
      //-- did the people who had to stay have a reason.
      if (total < C && stay != 0) {
	 possible = false;
      }
   }

   //-- train should end empty, and nobody
   //-- should be waiting at the last stop.
   if (total != 0 || stay != 0) {
      possible = false;
   }
      
   
   if (possible) {
      cout << "possible\n";
   } else {
      cout << "impossible\n";
   }
   
   return 0;
}
