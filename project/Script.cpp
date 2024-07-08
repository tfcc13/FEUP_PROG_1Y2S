#include <iostream>
#include <fstream>
#include "Script.hpp"
#include "PNG.hpp"
#include "XPM2.hpp"
#include <sstream>

using namespace std;

namespace prog 
{
    // Use to read color values from a script file.
    istream& operator>>(istream& input, Color& c) {
        int r, g, b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }

    Script::Script(const string& filename):image(nullptr), input(filename){}

    void Script::clear_image_if_any() {
        if (image != nullptr) {
            delete image;
            image = nullptr;
        }
    }

    Script::~Script() {
        clear_image_if_any();
    }

    void Script::run() {
        string command;
        while (input >> command) {
            cout << "Executing command '" << command << "' ..." << endl;
            if (command == "open") {
                open();
                continue;
            }
            if (command == "blank") {
                blank();
                continue;
            }
            // Other commands require an image to be previously loaded.
            if (command == "save") {
                save();
                continue;
            } 
            if(command == "invert"){
                invert();
                continue;
            }
            if(command == "to_gray_scale"){
                to_gray_scale();
                continue;
            }
            if(command == "replace"){
                replace();
                continue;
            }
            if(command == "fill"){
                fill();
                continue;
            }
            if(command == "h_mirror"){
                h_mirror();
                continue;
            }
            if(command == "v_mirror"){
                v_mirror();
                continue;
            }
            if(command == "add"){
                add();
                continue;
            }
            if(command == "crop"){
                crop();
                continue;
            }
            if(command == "rotate_left"){
                rotate_left();
                continue;
            }
            if(command == "rotate_right"){
                rotate_right();
                continue;
            }
            if(command == "median_filter"){
                median_filter();
                continue;
            }
            if(command == "xpm2_open"){
                xpm2_open();
                continue;
            }
            if(command == "xpm2_save"){
                xpm2_save();
                continue;
            }
        }
    }

    void Script::open() {
        // Replace current image (if any) with image read from PNG file.
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromPNG(filename);
    }

    void Script::blank() {
        // Replace current image (if any) with blank image.
        clear_image_if_any();
        int w, h;
        Color fill;
        input >> w >> h >> fill;
        image = new Image(w, h, fill);
    }

    void Script::save() {
        // Save current image to PNG file.
        string filename;
        input >> filename;
        saveToPNG(filename, image);
    }

    /*Inversão de cores de cada píxel de uma imagem:(r, g, b) para (255-r,255-g,255-b). São 
    utilizados iteradores para a iteração sobre todos os elementos do contentor utilizado para 
    armazenar os diferentes píxeis. A inversão do objeto Color é realizado através do método 
    'invert' implementado na classe Color. Este filtro equivale ao "negativo" de uma imagem*/
    void Script::invert(){
        image->invert();
    }
    
    // Transformação de cores de cada píxel (r, g, b) para (255-r,255-g,255-b).
    void Script::to_gray_scale(){
        image->to_gray_scale();
    }

    /*Substituição de todos os píxeis (r1, g1, b1) por píxeis (r2, g2, b2). A leitura do input
    é materializada através do getline, sendo feito posteriormente o assignment de cada um dos 
    atributos dos píxeis às variáveis do tipo int. Finalmente, faz-se a conversão de inteiro para 
    rgb_value. O método replace() da classe Image realiza a substituição de todos os píxeis com
    os mesmos atributos de c1 pelos atributos de c2.*/
    /*Nota: Após a leitura do command em run, a restante linha contém os inputs relevantes para
    o replace, tal como se poderá constatar nos ficheiros de texto na pasta 'script'.*/
    void Script::replace(){
        int r1, g1, b1, r2, g2, b2;
        input >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
        Color c1(static_cast<rgb_value>(r1),static_cast<rgb_value>(g1),static_cast<rgb_value>(b1)); 
        Color c2(static_cast<rgb_value>(r2),static_cast<rgb_value>(g2),static_cast<rgb_value>(b2));
        image->replace(c1,c2);        
    }

    /*Preencimento de todos os píxeis contidos no retângulo definido pelo canto superior esquerdo
    (x,y) com largura w e altura h, com a cor(r,g, b).*/
    void Script::fill(){
        int x, y, w, h, r, g, b;
        input >> x >> y >> w >> h >> r >> g >> b;
        Color c(static_cast<rgb_value>(r),static_cast<rgb_value>(g),static_cast<rgb_value>(b));
        image->fill(x,y,w,h,c);
    }

    /*Mirror horizontal de todos os píxeis de uma imagem (segundo um eixo vertical e centrado). É
    utilizada a member function 'h_mirror' da classe Image.*/
    void Script::h_mirror(){
        image->h_mirror();
    }

    /*Mirror vertical de todos os píxeis de uma imagem (segundo um eixo horizontal e centrado). É
    utilizada a member function 'h_mirror' da classe Image.*/
    void Script::v_mirror(){
        image->v_mirror();
    }

    
    //adiciona a uma imagem uma região de outra imagem
    void Script::add() {
        string filename;
        Color neutral_c;
        int y,x;
        input >> filename >> neutral_c >> x >> y;
        const Image *image2 = loadFromPNG(filename);
        image->add(image2 ,x, y, neutral_c);
        delete image2;
    }


    // recorta a imagem desde um canto superior esquerdo(x,y) até um ponto com altura h e largura w(w,h);
    void Script::crop(){
        int x, y, w, h;
        input >> x >> y >> w >> h;
        image->crop(x,y,w,h);
    }

    // roda a imagem para a esquerda
    void Script::rotate_left(){
        image ->rotate_left();

    }
    // roda a imagem para a esquerda
    void Script::rotate_right(){
        image->rotate_right();
    }

    void Script::xpm2_open(){
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromXPM2(filename);
    }

    void Script::xpm2_save(){
        // Save current image to PNG file.
        string filename;
        input >> filename;
        saveToXPM2(filename, image);
    }
    // reduz o ruído de uma imagem através da aplicação de um median filter
        void Script::median_filter() {
        int ws;
        input >> ws;
        image->median_filter(ws);

    }

}
