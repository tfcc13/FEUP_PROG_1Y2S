/*
The main idea of a "max filter" applied to a 2D matrix is to run through the matrix, element by element, replacing each element with the maximum of neighbouring elements. The neighbourhood is made of n by n elements, where n

is an odd number, except for the elements in the borders of the matrix.

For example
*/

#include <iostream>
#include <vector>

using namespace std;



 bool max_filter(vector<vector<int>> &v, int n) {
    
    if (n > int(v.size()) || n > int(v[0].size()) || n%2 == 0) return false;

    vector<vector<int>> v2(int(v.size()),vector<int>(int(v[0].size())));

    int radius = n /2;
    
    for (int i = 0; i < int(v.size()); i++ ) {
        for (int j = 0; j < int(v[0].size()); j++) {
            int maxim = -1000000;
            for (int k = i-radius; k <= i+radius; k++) {
                for (int l = j-radius; l <= j+radius;l++) {
                   if (k >= 0 && k < int(v.size()) && l >= 0 && l < int(v[0].size()) ) maxim = max(maxim,v[k][l]);
                }
            }
            v2[i][j] = maxim;
        }
        
    }
    v = v2;
    return true;
 }

void show_vector(const vector<vector<int>>& v) {
  cout << "{";
  for (const auto& line : v) {
    cout << "{ ";
    for (const auto& elem : line)
      cout << elem << ' ';
    cout << "}";
  }
  cout << "}";
}


 int main() {
  // public tests (1 point each)
  { 
    vector<vector<int>> v = { {1,2,3}, {4,5,6}, {7,8,9} };
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl; 
  } // -> true{{ 5 6 6 }{ 8 9 9 }{ 8 9 9 }}
  { 
    vector<vector<int>> v =
    { { 8,5,4,2,1 },
      { 1,2,4,5,9 },
      { 3,6,3,7,3 },
      { 5,7,8,1,4 },
      { 9,1,2,6,5 } };
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl;
  } // -> true{{ 8 8 5 9 9 }{ 8 8 7 9 9 }{ 7 8 8 9 9 }{ 9 9 8 8 7 }{ 9 9 8 8 6 }}
  { 
    vector<vector<int>> v = { { 8,5,4,2,1 }, { 9,1,2,6,5 } };
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl;
  }  // -> false{{ 8 5 4 2 1 }{ 9 1 2 6 5 }}
  { 
    vector<vector<int>> v =
    { { -8,-5,4,2,1,-1,7 },
      { -1,-2,4,5,9,0,4 },
      { -3,6,-3,-7,3,-10,-7 },
      { 5,7,8,1,4,-2,-31 },
      { -9,1,-2,6,5,-5,-16 } };
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl;
  }  // -> true{{ -1 4 5 9 9 9 7 }{ 6 6 6 9 9 9 7 }{ 7 8 8 9 9 9 4 }{ 7 8 8 8 6 5 -2 }{ 7 8 8 8 6 5 -2 }}
  { 
    vector<vector<int>> v =
    { { -8,-5,4,2,1,-1,7 },
      { -1,-2,4,5,9,0,4 },
      { -3,6,-3,-7,3,-10,-7 },
      { 5,7,8,1,4,-2,-31 },
      { -9,1,-2,6,5,-5,-16 } };
    bool b = max_filter(v, 5); cout << boolalpha << b;
    show_vector(v); cout << endl;
  }  // -> true{{ 6 6 9 9 9 9 9 }{ 8 8 9 9 9 9 9 }{ 8 8 9 9 9 9 9 }{ 8 8 9 9 9 9 9 }{ 8 8 8 8 8 6 5 }}
  cout << endl;
  // private tests (1000 points each)
  { 
    vector<vector<int>> v = vector<vector<int>>(10, vector<int>(2, 1));
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl;
  }  // -> false{{ 1 1 }{ 1 1 }{ 1 1 }{ 1 1 }{ 1 1 }{ 1 1 }{ 1 1 }{ 1 1 }{ 1 1 }{ 1 1 }}
  { 
    vector<vector<int>> v = { {8,5,1}, {4,2,6}, {1,3,7} };
    bool b = max_filter(v, 2); cout << boolalpha << b;
    show_vector(v); cout << endl;
  }  // -> false{{ 8 5 1 }{ 4 2 6 }{ 1 3 7 }}
  { 
    vector<vector<int>> v = { {1,2,3,1,7,2}, {4,1,3,5,6,1}, {7,8,9,1,1,0}, {0,3,1,2,6,1}, {1,2,3,6,5,4} };
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl;
  }  // -> true{{ 4 4 5 7 7 7 }{ 8 9 9 9 7 7 }{ 8 9 9 9 6 6 }{ 8 9 9 9 6 6 }{ 3 3 6 6 6 6 }}
  { 
    vector<vector<int>> v = vector<vector<int>>(10, vector<int>(10,0));
    for (size_t i = 1; i < v.size(); i++)
      v.at(i).at(i) = int(i);
    bool b = max_filter(v, 3); cout << boolalpha << b;
    show_vector(v); cout << endl;
  }  // -> true{{ 1 1 1 0 0 0 0 0 0 0 }{ 1 2 2 2 0 0 0 0 0 0 }{ 1 2 3 3 3 0 0 0 0 0 }{ 0 2 3 4 4 4 0 0 0 0 }{ 0 0 3 4 5 5 5 0 0 0 }{ 0 0 0 4 5 6 6 6 0 0 }{ 0 0 0 0 5 6 7 7 7 0 }{ 0 0 0 0 0 6 7 8 8 8 }{ 0 0 0 0 0 0 7 8 9 9 }{ 0 0 0 0 0 0 0 8 9 9 }}
  { 
    vector<vector<int>> v = vector<vector<int>>(7, vector<int>(8,0));
    v.at(5).at(3) = 1;
    bool b = max_filter(v, 5); cout << boolalpha << b;
    show_vector(v); cout << endl;
  }  // -> true{{ 0 0 0 0 0 0 0 0 }{ 0 0 0 0 0 0 0 0 }{ 0 0 0 0 0 0 0 0 }{ 0 1 1 1 1 1 0 0 }{ 0 1 1 1 1 1 0 0 }{ 0 1 1 1 1 1 0 0 }{ 0 1 1 1 1 1 0 0 }}

  return 0;
}