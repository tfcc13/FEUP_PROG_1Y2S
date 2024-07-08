#include "Color.hpp"

namespace prog
{
    // Default constructor: Por defeito, é atribuído o valor 0 a cada uma das 3 cores.
    Color::Color():red_(0),green_(0),blue_(0){}

    // Copy constructor. Cópia de outro objeto da classe color.
    Color::Color(const Color &other):red_(other.red()),green_(other.green()),blue_(other.blue()){}

    // Other constructor. Construção a partir do input de cada uma das 3 cores.
    Color::Color(rgb_value red, rgb_value green, rgb_value blue):red_(red),green_(green),blue_(blue){}

    // Accessor functions para cada uma das cores RGB.
    rgb_value Color::red() const{return red_;}
    rgb_value Color::green() const{return green_;}
    rgb_value Color::blue() const{return blue_;}

    /* Get (mutable) reference para cada uma das cores RGB. Permite obter uma ref dos atributos
    para que possam ser modificados. */
    rgb_value &Color::red(){return red_;}
    rgb_value &Color::green(){return green_;}
    rgb_value &Color::blue(){return blue_;}

    // Constantes das cores correspondentes ao vermelho, verde, azul, preto e branco. 
    const Color Color::RED(255,0,0);
    const Color Color::GREEN(0,255,0);
    const Color Color::BLUE(0,0,255);
    const Color Color::BLACK(0,0,0);
    const Color Color::WHITE(255,255,255);

    // Member function que muda o valor dos 3 atributos.
    void Color::setRGB(rgb_value red, rgb_value green, rgb_value blue){
        red_=red;
        green_=green;
        blue_=blue;
    }

    // Member function que inverte a cor do píxel do próprio objeto.
    void Color::invert(){
        red_ = 255-red_;
        green_ = 255-green_;
        blue_ = 255-blue_;
    }
 
    /*Member function que retorna o resultado da condição de igualdade do objeto da própria
    instância com outro objeto do tipo Color. Ambos 'const' para que não haja a possibilidade
    de serem modificados.*/ 
    bool Color::operator==(const Color& c1) const{
        return (red_==c1.red_ and green_==c1.green_ and blue_==c1.blue_);
    }

    /*Member function que retorna o resultado da condição de 'menor' entre o objeto da própria 
    instância em relação a outro do tipo Color. Este operador foi adicionado para que fosse 
    possível a utilização de um map cujas keys são da classe Color. Visto que nos maps todas as 
    chaves são ordenadas, é obrigatória a definição deste overload.*/
    bool Color::operator<(const Color& c1) const{
        if(red_==c1.red_ and green_==c1.green_){
            return blue_<c1.blue_;
        }
        else if(red_==c1.red_){
            return green_<c1.green_;
        }
        return red_<c1.red_;
    }
}
