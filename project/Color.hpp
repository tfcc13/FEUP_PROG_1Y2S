#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

namespace prog
{
    typedef unsigned char rgb_value;
    class Color
    {
    private:
        // Data members.
        rgb_value red_, green_, blue_;
    public:
        // Member functions.
        Color();
        Color(const Color &c);
        Color(rgb_value red, rgb_value green, rgb_value blue);
        rgb_value red() const;
        rgb_value &red();
        rgb_value green() const;
        rgb_value &green();
        rgb_value blue() const;
        rgb_value &blue();
        // Member functions adicionados.
        static const Color RED, GREEN, BLUE, BLACK, WHITE;
        void setRGB(rgb_value red, rgb_value green, rgb_value blue);
        void invert();
        bool operator==(const Color& c1) const;
        bool operator<(const Color& c1) const;
    };
}
#endif
