#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>
#include <algorithm>

namespace prog
{   typedef std::vector<std::vector<Color>>::iterator vec_row_it;
    typedef std::vector<std::vector<Color>>::reverse_iterator vec_rev_row_it;
    typedef std::vector<Color>::iterator vec_pix_it;
    typedef std::vector<Color>::reverse_iterator vec_rev_pix_it;
    typedef std::vector<std::vector<Color>> rgb_matrix;
    
    class Image
    {
    private:
        /*Data members. Optou-se por um vetor de vetores como contentor dos píxeis por 
        proporcionar uma utilização mais facilitada no contexto deste projeto, nomeadamente 
        a gestão de memória dinâmica e o vasto leque de métodos disponíveis.*/
        int width_, height_;
        rgb_matrix pixel_matrix_;
        rgb_value median_aux_cal(std::vector<rgb_value> med_vec);
    public:
        // Member functions.
        Image(int w, int h, const Color &fill = {255, 255, 255});
        /*Neste caso, não é necessário o destructor visto que a classe 'vector' já se encarrega
        de libertar toda a memória dinâmica alocada nos seus objetos.*/
        //~Image();
        int width() const;
        int height() const;
        Color &at(int x, int y);
        const Color &at(int x, int y) const;
        // Member functions adicionadas.
        void invert();
        void to_gray_scale();
        void replace(const Color& c1, const Color& c2);
        void fill(int x, int y, int w, int h, const Color& c);
        void h_mirror();
        void v_mirror();
        void add(const Image* Img_Source, int x, int y, const Color& neutral_c);
        void crop(int x, int y, int w, int h);
        void rotate_left();
        void rotate_right();
        void median_filter(int ws);
        Image& operator=(const Image& other);
    };
}
#endif
