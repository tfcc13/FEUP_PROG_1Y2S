#include <iostream>
#include "Color.h"

using namespace std;

int main() {
  // public tests (1 point each)
  {
    Color c (1, 2, 3);
    const Color& r = c;
    cout << (int) r.red() << ' '
         << (int) r.green() << ' '
         << (int) r.blue() << ' '
         << boolalpha << r.equal_to(r) << '\n';
  } // -> 1 2 3 true
  {
    cout << boolalpha
         << Color::WHITE.equal_to(Color::WHITE) << ' '
         << Color::BLACK.equal_to(Color::RED) << ' '
         << Color::BLUE.equal_to(Color::GREEN) << '\n';
  } // -> true false false
  {
    Color c(Color::WHITE);
    cout << (int) c.red() << ' '
         << (int) c.green() << ' '
         << (int) c.blue() << ' '
         << boolalpha << c.equal_to(Color::WHITE) << ' '
         << c.equal_to(Color::BLACK) << '\n';
  } // -> 255 255 255 true false
  {
    Color c(Color::WHITE);
    c.invert();
    cout << (int) c.red() << ' '
         << (int) c.green() << ' '
         << (int) c.blue() << ' '
         << boolalpha << c.equal_to(Color::WHITE) << ' '
         << c.equal_to(Color::BLACK) << '\n';
  } // -> 0 0 0 false true
  {
    Color c(255, 128, 12);
    c.invert();
    Color c2(c);
    c2.invert();
    cout << (int) c.red() << ' '
         << (int) c.green() << ' '
         << (int) c.blue() << ' '
         << boolalpha << c.equal_to({ 0, 127, 243 }) << ' '
         << (int) c2.red() << ' '
         << (int) c2.green() << ' '
         << (int) c2.blue() << ' '
         << boolalpha << c2.equal_to({ 255, 128, 12 }) << '\n';
  } // -> 0 127 243 true 255 128 12 true
  cout << '\n';
  // Private tests (1000 points each)
  {
    Color c (23, 122, 43);
    cout << (int) c.red() << ' '
         << (int) c.green() << ' '
         << (int) c.blue() << '\n';
  } // -> 23 122 43
  {
    cout << boolalpha
         << Color::BLACK.equal_to(Color::BLACK) << ' '
         << Color::BLACK.equal_to(Color::GREEN) << ' '
         << Color::RED.equal_to(Color::BLUE) << '\n';
  } // -> true false false
  {
    Color c(Color::BLACK);
    cout << (int) c.red() << ' '
         << (int) c.green() << ' '
         << (int) c.blue() << ' '
         << boolalpha << c.equal_to(Color::WHITE) << ' '
         << c.equal_to(Color::BLACK) << '\n';
  } // -> 0 0 0 false true
  {
    Color c(Color::BLACK);
    c.invert();
    cout << (int) c.red() << ' '
         << (int) c.green() << ' '
         << (int) c.blue() << ' '
         << boolalpha << c.equal_to(Color::WHITE) << ' '
         << c.equal_to(Color::BLACK) << '\n';
  } // -> 255 255 255 true false
  {
    Color c(0, 255, 1);
    c.invert();
    Color c2(c);
    c2.invert();
    cout << (int) c.red() << ' '
         << (int) c.green() << ' '
         << (int) c.blue() << ' '
         << boolalpha << c.equal_to({ 255, 0, 254 }) << ' '
         << (int) c2.red() << ' '
         << (int) c2.green() << ' '
         << (int) c2.blue() << ' '
         << boolalpha << c2.equal_to({ 0, 255, 1 }) << '\n';
  } // -> 255 0 254 false 0 255 1 false
  return 0;
}