/*

The Manhattan distance between 2 points (x1,y1) and (x2,y2) is given by |x1−x2|+|y1−y2|

.

Write a C++ program that that reads an integer number n by user input followed by n pairs of integer numbers (x1,y1)…(xn,yn)
, each defining a point, and then prints the Manhattan distance associated with the path defined by the n points, i.e., the sum of Manhattan distances between successive points in the path. 

*/

#include <iostream>

int main() {
    int n;
    int x1;
    int y1;
    int md =  0;
    std::cin >> n >> x1>>y1;
    

    int x2;
    int y2;


    for (int i = 1; i<n;i++){
        std::cin >> x2 >> y2;
        md +=  std::abs(x1-x2) + std::abs(y1-y2);
        y1 = y2;
        x1 = x2;    

    }

    std::cout << md;
    return 0;
}

/* public tests (1 point each)
2  0 1  1 3  
  -> 3
2  3 5  3 5
  -> 0
3  0 1  1 3  -2 0 
  -> 9
6  1 1  0 1  1 1  
   2 1  1 1  0 0 
  -> 6
9  0 0  1 2  3 4  
   5 6  3 4  1 2  
   -1 -2  -3 -4  -5 -6 
  -> 33
*/
/* private tests (1000 points each)
5 2 1  2 1  2 1  
  2 1  2 1 
  -> 0
2  0 2  1 13
  -> 12
3 0 1  2 4  -2 -3
  -> 16
12  1 1  0 1  1 1
    2 1  1 1  0 0
    1 2  0 2  1 21
    2 2  1 2  0 2  
  -> 52
15 0 0  1 2  3 4
   5 6  3 4  5 6 
   -1 -2  -3 -4  -5 -6
   5 6  3 4  1 2
   -1 -2  -3 -4  -5 -6
  -> 85
*/