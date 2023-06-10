/*
Write the C++ code for function cat_keys, declared as:

string cat_keys(list<map<string, unsigned>> lst);

The function should iterate the given list of maps to find the map that contains the minimum unsigned value, and returns a string that is a concatenation of all the keys in that map. See the public tests below for examples.

You may assume there is a single map with the minimum unsigned value. Note that UINT_MAX, defined in header <climits>, is the constant for the maximum value of an unsigned integer value. 
*/


#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <list>

using namespace std;


string cat_keys(list<map<string, unsigned>> lst) {

    unsigned minim = UINT_MAX;
    map<string, unsigned> min_map;
    
    for (map<string,unsigned>  const &m : lst) {
        for( const pair<string,unsigned>& n : m) {
            if(n.second < minim) {
                minim = n.second;
                min_map = m;
            }
        }
    }

    string result = "";

    for( const pair<string,unsigned>& n : min_map) {

        result += n.first;

}

return result;

}


int main() {

    { list<map<string, unsigned>> m2 = {
    { {"s1", 13}, {"s2", 2} } };
  cout << cat_keys(m2) << endl; }

	

//ss1s2

{ list<map<string, unsigned>> m1 = {
    { {"s1", 1} } };
  cout << cat_keys(m1) << endl; }

	

//s1

{ list<map<string, unsigned>> m3 = {
    { {"s1", 13}, {"s2", 2} }, 
    { {"s3", 3}, {"s4", 4} }, { {"s5", 16} } };
  cout << cat_keys(m3) << endl; }

	

//s1s2

{ list<map<string, unsigned>> m4 = {
    { {"s1", 13}, {"s2", 4} }, { {"s3", 3}, {"s4", 4} } };
  cout << cat_keys(m4) << endl; }

	

//s3s4

return 0;

}
