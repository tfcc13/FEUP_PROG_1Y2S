#include "Color.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue) : red_(red), blue_(blue), green_(green) {}

Color::Color(const Color& c) {
    red_ = c.red_;
    blue_ = c.blue_;
    green_ = c.green_;
 } 

unsigned char Color::red() const {
    return red_;
 }

unsigned char Color::blue() const {
    return blue_;
 }

unsigned char Color::green() const {
    return green_;
 }

bool Color::equal_to(const Color& other) const {
    if (red_ != other.red() || blue_ != other.blue() || green_ != other.green()) return false;
    return true;
}

void Color::invert() {
    red_ = 255-red_;
    blue_ = 255-blue_;
    green_ = 255-green_;
}

const Color Color::RED(255,0,0);
const Color Color::BLUE(0,255,0);
const Color Color::GREEN(0,0,255);
const Color Color::BLACK(0,0,0);
const Color Color::WHITE(255,255,255);