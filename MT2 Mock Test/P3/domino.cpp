/*
Consider designing a class to partially implement a Domino game considering only a deck of pieces and the line of played pieces left-to-right "on the table". A domino piece has two sides, each one with a number in the range from '0' to '6'. The numbers may be equal on both sides of a piece and the complete set of pieces must not have repeated pieces. Nevertheless, when placed in the domino line, the piece 🀽 (1:5) is different from the piece 🁕 (5:1).

domino line

A piece of the domino game, when placed in the domino line, is represented by a class Piece as given in the header Piece.h.

class Piece {
public:
  // Constructor with parameters
  Piece(int left, int right) : left_(left), right_(right) { }
  // Determine if this piece can be placed on the left of the other piece
  bool can_be_left_to(const Piece& other) const;
  // Determine if this piece can be placed on the right of the other piece
  bool can_be_right_to(const Piece& other) const;
  // Accessors
  int get_left() const { return left_; }
  int get_right() const { return right_; }
  string to_string() const { 
    ostringstream os;
    os << left_ << ‘:’ << right_;
    return os.str();
  }
private:
  // The points in the two sides of the piece
  int left_, right_;
};

The class Domino to represent part of the game is defined and partially implemented as given in the header Domino.h:

class Domino {
public:
  // Constructor with parameters
  Domino(const list<Piece>& initial) : pieces_(initial) { }
  // Get the left end of the domino line
  const Piece& left() const;
  // Get the right end of the domino line
  const Piece& right() const;
  // Place piece in the left end
  bool place_left(const Piece& p);
  // Place piece in the right end
  bool place_right(const Piece& p);
  // Display the domino line of pieces
  string to_string() const {
    string s("[");
    for(auto p: pieces_) 
      s.append(" ").append(p.to_string());
    s.append(" ]");
    return s;
  }
private:
  // The line of played pieces "on the table"
  list<Piece> pieces_;
};

Complete the code of classes Piece and Domino with the implementation of the six member functions not yet implemented. 
*/


#include <iostream>
#include <string>
#include <list>
#include "Piece.h"
#include "Domino.h"

bool Piece::can_be_left_to(const Piece& other) const {
    return other.left_ == right_;
}

bool Piece::can_be_right_to(const Piece& other) const {
    return other.right_ == left_;
}

const Piece& Domino::left() const {
    return pieces_.front();
 }

const Piece& Domino::right() const {
    return pieces_.back();
 }

bool Domino::place_left(const Piece& p) {
    if (p.can_be_left_to(pieces_.front())) {
        pieces_.push_front(p);
        return true;
    }
    return false;
}


bool Domino::place_right(const Piece& p) {
    if (p.can_be_right_to(pieces_.back())) {
        pieces_.push_back(p);
        return true;
    }
    return false;
}

int main() {

    { Piece p (1, 2);
  cout << boolalpha 
       << p.can_be_left_to({2, 3}) << ' ' 
       << p.can_be_left_to({3, 2}) << ' ' 
       << p.can_be_right_to({3, 2}) << ' ' 
       << p.can_be_right_to({0, 1}) << '\n'; }

	

//true false false true

{ Domino d( { {1,2}, {2,0}, {0,6}, {6,6} } );
  cout << d.left().to_string() << ' '
       << d.right().to_string() << ' '
       << d.to_string() << '\n'; }

	

//1:2 6:6 [ 1:2 2:0 0:6 6:6 ]

{ Domino d( { {1,2}, {2,0}, {0,6}, {6,6} } );
  cout << boolalpha
       << d.place_left({6,1})  << ' '
       << d.place_right({3,6}) << ' '
       << d.to_string() << '\n'; }

	

//true false [ 6:1 1:2 2:0 0:6 6:6 ]

{ Domino d( { {1,2}, {2,3}, {3,3}, {3,4} } );
  cout << boolalpha
       << d.place_left({4,3})  << ' '
       << d.place_right({4,1}) << ' '
       << d.to_string() << '\n'; }

	

//false true [ 1:2 2:3 3:3 3:4 4:1 ]

{ Domino d( { {1,2}, {2,3}, {3,3}, {3,6} } );
  cout << boolalpha
       << d.place_left({1,1})  << ' '
       << d.place_right({6,6}) << ' '
       << d.to_string() << '\n'; }

	

//true true [ 1:1 1:2 2:3 3:3 3:6 6:6 ]

    return 0;
}