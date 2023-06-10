/*
Consider the definition of an abstract class Operation given in header file Operation.h, that represents operations over two integers:

class Operation {
public:
  Operation(int op1, int op2) : op1_(op1), op2_(op2) { };
  int get_op1() const { return op1_; }
  int get_op2() const { return op2_; }
  virtual int operation() const = 0;  // operation
private:
  int op1_, op2_;  // two operands
};

Implement the definition of classes Sum and Power such that they implement, respectively, the addition of the two integers, and raising the first integer to the power of the second. Consider that the exponent argument to Power is always greater or equal than 0.


*/



#include "Operation.h"
#include <iostream>

using namespace std;



class Sum : public Operation {
    public:

    Sum(int x, int y) : Operation(x,y) {}


    virtual int operation() const {
        return this->get_op1() + this->get_op2() ;
    }
};
class Power : public Operation {
    public: 
    
    Power(int x, int y) : Operation(x,y) {}
    
    virtual int operation() const {
        int n = this->get_op2() ;
        int res = 1;

        for (int i = 1; i <= n; i++) {
            res *= this->get_op1();
        }
        return res;
    }


};

    int main(int argc, char const *argv[]) {
  // public tests (1 point each)
  {
    const Operation& s = Sum(2, 10); cout << s.operation() << ' '; 
    const Operation& p = Power(2, 10); cout << p.operation() << endl;
  } // -> 12 1024
  {
    Sum s(6, -2); cout << s.operation() << ' '; 
    Power p(-3, 0); cout << p.operation() << endl;
  } // -> 4 1
  {
    Sum s(-6, 2); cout << s.operation() << ' '; 
    Power p(-2, 5); cout << p.operation() << endl;
  } // -> -4 -32
  {
    Sum s(-6, -2); cout << s.operation() << ' '; 
    Power p(2, 7); cout << p.operation() << endl;
  } // -> -8 128
  cout << endl;
  // private tests (1000 points each)
  {
    Sum s(10, 22); cout << s.operation() << ' '; 
    Power p(2, 12); cout << p.operation() << endl;
  } // -> 32 4096
  {
    Sum s(60, -22); cout << s.operation() << ' '; 
    Power p(-3, 13); cout << p.operation() << endl;
  } // -> 38 -1594323
  {
    Sum s(-06, 26); cout << s.operation() << ' '; 
    Power p(-3, 5); cout << p.operation() << endl;
  } // -> 20 -243
  {
    Sum s(-666, 666); cout << s.operation() << ' '; 
    Power p(2, 20); cout << p.operation() << endl;
  } // -> 0 1048576

  return 0;
}


