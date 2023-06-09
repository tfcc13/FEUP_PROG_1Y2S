/*
Write a C++ function void count_words(const string& str, map<string, size_t>& count), that receives as parameters a string and a map, and fills the map with the number of occurrences of each word in the string. Consider the words case insensitive and the keys in lowercase.

Include the following function, show_map, to print the contents of the map in the test cases.

void show_map(const map<string, size_t>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}
*/

#include <iostream>
#include <map>
#include <string>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>

using namespace std;


void count_words(const string& str, map<string, size_t>& count) {
    istringstream iss(str);

    string word;

    while (iss >> word) {
        for (char &c : word) {
            c = tolower(c);
        }

        if(count.find(word) == count.end()) {
             count.insert(make_pair(word, 1));
        }

        else {
            count.find(word)->second++;
        }
    }

}

void show_map(const map<string, size_t>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}

int main() {
  cout << endl;
  // public tests (1 point each)
  {
    string s = "If you want to buy  buy  if you don't want to buy  bye bye";
    map<string, size_t> count; 
    count_words(s, count);
    show_map(count);
  }  // -> [ buy:3 bye:2 don't:1 if:2 to:2 want:2 you:2 ]
  {
    string s = "You can fool some of the people all of the time and all of the people some of the time  but you cannot fool all of the people all of the time";
    map<string, size_t> count; 
    count_words(s, count);
    show_map(count);
  }  // -> [ all:4 and:1 but:1 can:1 cannot:1 fool:2 of:6 people:3 some:2 the:6 time:3 you:2 ]
  {
    string s = "A tutor who tooted the flute tried to tutor two young tooters to toot   Said the two to the tutor is it tougher to toot or to tutor two young tooters to toot";
    map<string, size_t> count;
    count_words(s, count);
    show_map(count);
  } // -> [ a:1 flute:1 is:1 it:1 or:1 said:1 the:3 to:6 toot:3 tooted:1 tooters:2 tougher:1 tried:1 tutor:4 two:3 who:1 young:2 ]
  {
    string s = "You do not need to turn on a night light on a clear night like tonight because in a clear night there is always a light light and tonight is a clear night";
    map<string, size_t> count;
    count_words(s, count);
    show_map(count);
  } // -> [ a:5 always:1 and:1 because:1 clear:3 do:1 in:1 is:2 light:3 like:1 need:1 night:4 not:1 on:2 there:1 to:1 tonight:2 turn:1 you:1 ]
  {
    string s = "If one doctor doctors another doctor  Does the doctor who doctors the doctor  Doctor the way the doctor he is doctoring doctor  Or does he doctor the doctor  The way the doctor who doctors doctor";
    map<string, size_t> count;
    count_words(s, count);
    show_map(count);
  } // -> [ another:1 doctor:11 doctoring:1 doctors:3 does:2 he:2 if:1 is:1 one:1 or:1 the:7 way:2 who:2 ]

  cout << endl;
  // private tests (1000 points each)
  {
    string s = "If Freaky Fred found fifty feet of fruit  And fed forty feet to his friend Frank  How many feet of fruit did Freaky Fred find";
    map<string, size_t> count;
    count_words(s, count);
    show_map(count);
  } // -> [ and:1 did:1 fed:1 feet:3 fifty:1 find:1 forty:1 found:1 frank:1 freaky:2 fred:2 friend:1 fruit:2 his:1 how:1 if:1 many:1 of:2 to:1 ]
  {
    string s = "I wish to wish the wish you wish  But if you wish the wish the witch wishes  I won't wish the wish you wish to wish";
    map<string, size_t> count;
    count_words(s, count);
    show_map(count);
  } // -> [ but:1 i:2 if:1 the:4 to:2 wish:10 wishes:1 witch:1 won't:1 you:3 ]
  {
    string s = "A tutor who tooted the flute  Tried to tutor two tooters to toot";
    map<string, size_t> count;
    count_words(s, count);
    show_map(count);
  } // -> [ a:1 flute:1 the:1 to:2 toot:1 tooted:1 tooters:1 tried:1 tutor:2 two:1 who:1 ]
  {
    string s = "Love is a feeling you feel  When you feel  You are going to feel the feeling  You have never felt before";
    map<string, size_t> count;
    count_words(s, count);
    show_map(count);
  } // -> [ a:1 are:1 before:1 feel:3 feeling:2 felt:1 going:1 have:1 is:1 love:1 never:1 the:1 to:1 when:1 you:4 ]
  {
    string s = "How much wood would a woodchuck chuck  If a woodchuck could chuck wood  A woodchuck would chuck as much wood  As a woodchuck would chuck  If a woodchuck could chuck wood";
    map<string, size_t> count;
    count_words(s, count);
    show_map(count);
  } // -> [ a:5 as:2 chuck:5 could:2 how:1 if:2 much:2 wood:4 woodchuck:5 would:3 ]

  return 0;
}

