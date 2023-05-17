/*
Run-length encoding (RLE) is a form of data compression in which "runs" of data (sequences in which the same data value occurs in many consecutive data elements) are stored as a single data value and count; this is most useful on data that contains many long runs. For example, the RLE encoding of “aaaaabbbbbbbbbbbcccd” is “5a11b3c1d”.

Write a C++ function void rle_encode(const char str[], char rle[]) that takes the input C string str containing only non-digit characters (‘0’ to ‘9’ cannot occur) and computes the RLE encoding of str in rle.

You cannot use any library classes or functions, including the string, stringstream, vector, and list C++ classes or the sprintf function.

Hint: it can be useful to think first of a function void int_to_string(int n, char str[], int& pos) that writes the digits of n to str starting from position pos. On exit, pos contains the next usable position. 
*/

#include <iostream>
using namespace std;


void int_to_str(int n, char str[], int& pos) {
   
    int d = 0;

    for (int i = n ; i != 0; i = i/10) {
        d++;
    }
    for (int i = d, j = n; i > 0; i--) {
    str[pos + i - 1] = '0' + j % 10;
    j = j / 10;
  }
  pos = pos + d;

}


void rle_aux(int ocurr_c, char c, char rle[], int& pos) {
    if (ocurr_c == 0) {
        return;
    }

    int_to_str(ocurr_c, rle, pos) ;
    rle[pos] = c;
    pos++;
}


void rle_encode(const char str[], char rle[]) {
    int curr_pos_str = 0;
    int curr_pos_rle = 0;
    char c = 0;
    int ocurr_c = 0;

    while(str[curr_pos_str]!= '\0') {
        if (str[curr_pos_str] == c) {
            ocurr_c++;
        }
        else {
            rle_aux (ocurr_c, c, rle, curr_pos_rle);
            ocurr_c = 1;
            c = str[curr_pos_str];
        }
        curr_pos_str++;
    }
    rle_aux(ocurr_c, c, rle, curr_pos_rle);

    rle[curr_pos_rle] = '\0';
    


}
int main() {

      // public tests (1 point each)
  {
    char rle[1] = { -1 }; 
    rle_encode("", rle);
    cout << rle << endl;
  } // => 
  {
    char rle[2 + 1] = { -1, -1, -1 }; 
    rle_encode("a", rle);
    cout << rle << endl;
  } // => 1a
  {
    char rle[10 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; 
    rle_encode("abcde", rle);
    cout << rle << endl;
  } // => 1a1b1c1d1e
  {
    char rle[9 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
    rle_encode("aaaaabbbbbbbbbbbcccd", rle);
    cout << rle << endl;
  } // => 5a11b3c1d
  {
    char rle[3 + 1] = { -1, -1, -1, -1 }; 
    rle_encode("xxxxxxxxxxxxxxxxxxxx", rle);
    cout << rle << endl;
  } // => 20x
  
  cout << endl;
  // private tests (1000 points each)
  {
    char rle[3 + 1] = { -1, -1, -1, -1 }; 
    rle_encode("xxxxxxxxxxxx", rle);
    cout << rle << endl;
  } // => 12x
  {
    char rle[10 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
    rle_encode("xxxyyxxyxxxx", rle);
    cout << rle << endl;
  } // => 3x2y2x1y4x
  {
    char rle[9 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
    rle_encode("aaaabbbbbbbbbbbbbcccddd", rle);
    cout << rle << endl;
  } // => 4a13b3c3d
  {
    char rle[16 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
    rle_encode("aabbccddaabbccdd", rle);
    cout << rle << endl;
  } // => 2a2b2c2d2a2b2c2d
  {
    char rle[19 + 1] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; 
    rle_encode("wwwwwwwwwwwwxxxyyuxaaabbboooooocccccccc", rle);
    cout << rle << endl;
  } // => 12w3x2y1u1x3a3b6o8c
    return 0;
}