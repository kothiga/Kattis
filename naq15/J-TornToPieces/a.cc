/*
  Solution for NAQ2015 problem j
  https://open.kattis.com/problems/torn2pieces

     Compile : g++11 -std=c++11 -o j j.cc -Wall
  Written by : Austin Kothig
    Semester : FALL 2017
     Problem : given peices of a subway map, print out
               the shortest route from some start
               station, to some end station
*/

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;

vector < vector <int> > m;

int main() {

   int N, index = 0;
   cin >> N; cin.ignore();

   map<string, int> key;
   vector<string> keyB;
   while (N--) {

      string s, start, next;
      getline(cin, s); istringstream ss(s);
      ss >> start;

      // set the key
      if (key.find(start) == key.end() ) {
	 key[start] = index++;
	 vector<int> temp;
	 m.push_back(temp);

	 // set the backwards key
	 keyB.push_back(start);
      }
      
      while (ss >> next) {
	 // if this station is not
	 // in our key - add it to the key
	 // and create an instance in
	 // the adj list
	 if ( key.find(next) == key.end() ) {
	    key[next] = index++;
	    vector <int> t;
	    m.push_back(t);
	    keyB.push_back(next);
	 }

	 // connect both stations
	 m[key[start]].push_back(key[next]);
	 m[key[next]].push_back(key[start]);
      }
   }

   string start, end;
   cin >> start >> end;

   if (key.find(start) == key.end() || key.find(end) == key.end()) {
      cout << "no route found\n";
   }

   else {

      // bfs
      vector<int> parent(index, -1);
      vector<bool> seen (index, false);
      queue<int> q;
      int goal = key[end], first = key[start];
      parent[first] = first;

      q.push(first);

      while (!q.empty()) {
	 // get the next instance
	 int f = q.front(); q.pop();

	 // reached the goal. leave.
	 if (f == goal) {
	    break;
	 }

	 // if this node has not been visited
	 if (!seen[f]) {
	    // say you have been here
	    seen[f] = true;

	    // go through the children
	    // and set their parent
	    for (unsigned int i = 0; i < m[f].size(); i++) {

	       if (!seen[m[f][i]]) {
		  parent[m[f][i]] = f;
		  q.push(m[f][i]);
	       }
	    }
	 }
      }

      // a path exists
      if (parent[goal] != -1) {
	 // recover the path
	 vector<int> path;
	 int cur = goal;

	 path.push_back(goal);
	 while (cur != first) {
	    cur = parent[cur];
	    path.push_back(cur);
	 }
      
	 for (int i = path.size()-1; i > -1; i--) {
	    cout << keyB[path[i]];
	    if (i) cout << " ";
	 }
	 cout << endl;   
      }

      else
	 cout << "no route found\n";
   }
}
   
