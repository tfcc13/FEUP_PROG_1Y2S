#include "XPM2.hpp"
#include <sstream>
#include <fstream>
#include <map>
#include <iomanip>

namespace prog {
    
    /*Leitura e armazenamento de um ficheiro XPM2 num objeto da classe Image. Esta função 
    retorna um apontador para a instância de Image criada, que deverá ser posteriormente 
    apagada para evitar memory leaks.*/
    Image* loadFromXPM2(const std::string& file){
        std::ifstream input(file);
        std::string fileLine;

        std::getline(input,fileLine); // leitura do cabeçalho.
        if(fileLine!="! XPM2"){return nullptr;} // verificação da validade do cabeçalho.

        /*Leitura da largura e altura da imagem a processar, do número de cores a incluir 
        no map para descodificar o ficheiro e do número de chars por cor.*/
        int width, height, numberOfColors, numberOfChars;
        input >> width >> height >> numberOfColors >> numberOfChars;

        // Construção do map de descodificação do ficheiro.
        std::map<char,Color> mapCharToColor;
        rgb_value red, green, blue;
        char currentChar, separator;
        std::string hexRGB;
        for(int currentColor = 0; currentColor<numberOfColors; currentColor++){
            input >> currentChar >> separator >> hexRGB;
            /*stoi devolve a conversão de uma string especificada numa determinada base 
            (neste caso, hexadecimal), para um número inteiro. Com o método subtring de string, 
            permite-se a leitura dos chars de cada cor RGB (2 hexas, 8 bits).*/ 
            red = std::stoi(hexRGB.substr(1,2),nullptr,16);
            green = std::stoi(hexRGB.substr(3,2),nullptr,16);
            blue = std::stoi(hexRGB.substr(5,2),nullptr,16);
            mapCharToColor.insert({currentChar,{red,green,blue}});
        }

        getline(input,fileLine); // ignorar linha;
        // Preenchimento da pixel_matrix_ do objeto criado (image).
        Image* image = new Image(width, height);
        int y = 0;
        while(getline(input,fileLine)){
            for(int x = 0; x<width; x++){
                image->at(x,y) = mapCharToColor.at(fileLine.at(x));
            }
            y++;
        }
        return image;
    }

    /*Construção de um ficheiro no formato XPM2, a partir de um objeto da classe Image.*/
    void saveToXPM2(const std::string& file, const Image* image){
        int width = image->width(), height = image->height();

        std::map<Color,char> mapColorToChar;
        Color pixel;
        char currentChar = 'A';
        /*Construção do map de descodificação dos píxeis (com base nos seus valores) e dos
        respetivos carateres. Neste caso, utilizaram-se carateres a partir da letra 'A'.*/
        for(int x = 0; x<width; x++){
            for(int y = 0; y<height; y++){
                pixel = image->at(x,y);
                std::map<Color,char>::iterator itr = mapColorToChar.find(pixel);
                // Caso o píxel não exista, adicionar key-value ao mapa.
                if(itr == mapColorToChar.end()){
                    mapColorToChar.insert({pixel,currentChar});
                    currentChar++; // Próxima letra, por ordem alfabética.
                }
            }
        }

        std::ofstream output(file);
        // Escrita do cabeçalho.
        output << "! XPM2" << '\n';
        /*Escrita da largura e altura da imagem a processar, do número de cores a incluir 
        no map para descodificar o ficheiro e do número de chars por cor.*/
        output << width << " " << height << " " << mapColorToChar.size() << " " << 1 << '\n';
        /*Escrita do map de descodificação. Os números na base hexadecimal são escritos sempre 
        com 2 carateres (caso seja necessário, dar fill com '0' à esquerda) e em uppercase, em 
        conformidade com o formato XPM2.*/
        for(std::map<Color,char>::iterator itr = mapColorToChar.begin(); itr!=mapColorToChar.end(); itr++){
            output << itr->second << " c #";
            output << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << static_cast<int>(itr->first.red());
            output << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << static_cast<int>(itr->first.green());
            output << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << static_cast<int>(itr->first.blue());
            output << '\n';
        }
        // Escrita, linha a linha, de todos os píxeis através do respetivo caratere de descodificação.
        for(int y = 0; y<height; y++){
            for(int x = 0; x<width; x++){
                output << mapColorToChar.at(image->at(x,y));
            }
            output << '\n';
        }
    }
}

