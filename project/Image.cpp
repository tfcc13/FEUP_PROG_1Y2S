#include "Image.hpp"
#include <iostream>
#include <string>

namespace prog
{   
    // Constructor com valores default de fill = (255, 255, 255) (branco).
    Image::Image(int w, int h, const Color &fill)
    {
        width_ = w;
        height_ = h;
        pixel_matrix_.resize(height_,std::vector<Color>(width_,fill));
    }

    /*Neste caso, não é necessário o destructor visto que a classe 'vector' já se encarrega
    de libertar toda a memória dinâmica alocada nos seus objetos.*/
    //Image::~Image(){}

    // Accessor functions para os atributos width_ e height_.
    int Image::width() const{return width_;}
    int Image::height() const{return height_;}

    /* Get (mutable) reference para um dos píxeis do contentor de vetor de vetores. Nota: x
    representa a "coluna" e y as "linhas". */
    Color &Image::at(int x, int y){
        return pixel_matrix_.at(y).at(x);
    }
    const Color &Image::at(int x, int y) const{
        return pixel_matrix_.at(y).at(x);
    }

    // Overload do operador "="
    Image& Image::operator=(const Image& other) {  //se imagem igual não executa;
       if (this == &other) {
            return *this;
       }
       
       width_ = other.width_; // altera valores de altura e largura da imagem.
       height_ = other.height_;

       pixel_matrix_.resize(height_); // atualiza a altura da imagem.

       for (int y = 0; y < height_; y++){ // atualiza a largura da imagem
        pixel_matrix_[y].resize(width_);
       }

       for (int y = 0; y < height_; y++){ // atribui os valores dos pixeis a cada célula
        
        for (int x = 0; x <width_; x++){
        pixel_matrix_[y][x]= other.pixel_matrix_[y][x];
        }
       }

       return *this;
    }

    /*Inversão de cores de cada píxel de uma imagem:(r, g, b) para (255-r,255-g,255-b). São 
    utilizados iteradores para a iteração sobre todos os elementos do contentor utilizado para 
    armazenar os diferentes píxeis. A inversão do objeto Color é realizado através do método 
    'invert' implementado na classe Color. Este filtro equivale ao "negativo" de uma imagem*/
    void Image::invert(){
        vec_row_it RowIt;
        vec_pix_it pixelIt;
        for(RowIt = pixel_matrix_.begin(); RowIt != pixel_matrix_.end(); RowIt++){
            for(pixelIt = RowIt->begin(); pixelIt != RowIt->end(); pixelIt++){
                pixelIt->invert();
            }
        }
    }

    /*Transformação de cores de cada píxel (r, g, b) para (255-r,255-g,255-b). A mudança de
    cada um dos atributos de Color é realizado através de um método 'setRGB' implementado na 
    classe Color*/
    void Image::to_gray_scale(){
        vec_row_it RowIt;
        vec_pix_it pixelIt;
        for(RowIt = pixel_matrix_.begin(); RowIt != pixel_matrix_.end(); RowIt++){
            for(pixelIt = RowIt->begin(); pixelIt != RowIt->end(); pixelIt++){
                rgb_value v = (pixelIt->red()+pixelIt->green()+pixelIt->blue())/3;
                pixelIt->setRGB(v,v,v);
            }
        }
    }

    //Substituição de todos os píxeis com os mesmos atributos de c1 pelos atributos de c2.
    void Image::replace(const Color& c1, const Color& c2){
        vec_row_it RowIt;
        vec_pix_it pixelIt;
        for(RowIt = pixel_matrix_.begin(); RowIt != pixel_matrix_.end(); RowIt++){
            for(pixelIt = RowIt->begin(); pixelIt != RowIt->end(); pixelIt++){
                if(*pixelIt==c1){
                    pixelIt->setRGB(c2.red(),c2.green(),c2.blue());
                }
            }
        }   
    }
    
    /*Preencimento de todos os píxeis contidos no retângulo definido pelo canto superior esquerdo
    (x,y) com largura w e altura h, com a cor(r,g, b).*/
    void Image::fill(int x, int y, int w, int h, const Color& c){
        vec_row_it RowIt;
        vec_pix_it pixelIt;
        for(RowIt = pixel_matrix_.begin()+y; RowIt != pixel_matrix_.begin()+y+h; RowIt++){
            for(pixelIt = RowIt->begin()+x; pixelIt != RowIt->begin()+x+w; pixelIt++){
                pixelIt->setRGB(c.red(),c.green(),c.blue());
            }
        }   
    }

    /*Mirror horizontal de todos os píxeis de uma imagem (segundo um eixo vertical e centrado).
    O iterador RowIt percorre todos os vetores (linhas) dentro do próprio vetor de vetores.
    Dentro de cada um destes vetores (linhas), criam-se dois iteradores: FowardIt que itera todos 
    os píxeis na ordem normal; ReverseIT que percorre todos os píxeis na ordem reversa. Não é 
    possível fazer uma comparação entre estes dois iteradores (origina erros de compilação).
    Deste modo, utilizou-se o ReverIt.base() que devolve um iterador de ordem normal que 
    aponta para o elemento imediatamente a seguir ao ReverseIt, contruindo-se desta forma o 
    critério de paragem. Para mais informações sobre std::reverse_iterator::base, ler:
    https://cplusplus.com/reference/iterator/reverse_iterator/base/*/
    void Image::h_mirror(){
        vec_row_it RowIt;
        for(RowIt=pixel_matrix_.begin();RowIt<pixel_matrix_.end();RowIt++){
            vec_pix_it FowardIt = RowIt->begin();
            vec_rev_pix_it ReverseIt = RowIt->rbegin();
            while(FowardIt < ReverseIt.base()){
                std::swap(*FowardIt,*ReverseIt);
                FowardIt++;
                ReverseIt++;
            }
        }
    }

    /*Mirror vertical de todos os píxeis de uma imagem (segundo um eixo horizontal e centrado). 
    Esta member function segue o mesmo raciocínio lógico da anterior. Neste caso, basta realizar 
    a substituição dos vetores (linhas) do vetor principal (matriz de píxeis), recorrendo ao
    algoritmo da STL, swap_ranges. swap_range.*/
    void Image::v_mirror(){
        vec_row_it TopRange = pixel_matrix_.begin();
        vec_rev_row_it BottomRange = pixel_matrix_.rbegin();
        while(TopRange<BottomRange.base()){
            std::swap_ranges(TopRange->begin(), TopRange->end(), BottomRange->begin());
            TopRange++;
            BottomRange++;
        }
    }
    
    /* Recebe um apontador para uma imagem a copiar, as coordenadas (x,y) do topo do rectangulo afetado e a cor neutra a não copiar*/
    void Image::add(const Image* Img_Source, int x, int y, const Color& neutral_c) {
        vec_row_it RowIt; // iterador de rows de vetores
        vec_pix_it pixelIt; // iteradores dos pixeis(colunas)
        vec_row_it Src_RowIt; // iterador de rows de vetores da imagem a ser copiada
        vec_pix_it Src_pixelIt; // iteradores dos pixeis(colunas) da imagem a ser copiada
        rgb_matrix src_matrix = Img_Source->pixel_matrix_; // acessa a matriz dos vectores da imagem a ser copiada
        RowIt = pixel_matrix_.begin()+y; // coloca o iterador das rows na row inicial do rectangulo a ser alterado na imagem atual

        for(Src_RowIt = src_matrix.begin(); Src_RowIt != src_matrix.end(); Src_RowIt++) { // percorre as rows da imagem a ser copiada
        
            pixelIt = RowIt->begin()+x; // coloca o iterador dos pixeis na coluna inicial do rectangulo a ser alterado na imagem atual
 
            for (Src_pixelIt = Src_RowIt->begin(); Src_pixelIt != Src_RowIt->end(); Src_pixelIt++) { // percorre os pixeis (colunas) da imagem  a ser copiada 
                if(*Src_pixelIt == neutral_c){ // se igual a cor neutra nao copia e salta uma coluna
                    pixelIt++;
                }
                else {
                *pixelIt = *Src_pixelIt; // copia e salta uma coluna
                pixelIt++;
                }
            }
            RowIt++; // passa para a próxima row
        }  
    }

    // Recorta a imagem desde um canto superior esquerdo (x,y) até uma largura e altura definida (w,h) 
    void Image::crop(int x, int y, int w, int h) {
      
        Image new_image(w,h); 

        vec_row_it RowIt; // iterador das rows da imagem atual
       
        vec_row_it  New_RowIt = new_image.pixel_matrix_.begin(); //iterador das rows da nova imagem recortada

        for (RowIt = pixel_matrix_.begin() + y; RowIt != pixel_matrix_.begin() + y +h; RowIt++, New_RowIt++) {
            vec_pix_it pixelIt; // iterador dos pixeis da row atual da imagem original
            vec_pix_it New_pixelIt; // iterador dos pixeis da row atual da imagem recortada
            New_pixelIt = New_RowIt -> begin();//ler  comentário anterior
            for(pixelIt = RowIt -> begin() + x; pixelIt != RowIt -> begin() + x +w; pixelIt++, New_pixelIt++) {
                *New_pixelIt = *pixelIt;
            }

        }

        *this = new_image;

        /*
        
        for (int i = y; i < y+h; i++) {
            for (int j = x; j <x+w; j++) {
                new_image.pixel_matrix_[i-y][j-x] = pixel_matrix_[i][j];
            } 
        }

        *this = new_image;
        */
    }

    /* roda a imagem para a esquerda, copiando as rows de cima para baixo ,da imagem original para as colunas, da esquerda para 
    a direita, da nova imagem*/
    void Image::rotate_left() {
        
        Image new_image(height_,width_); 

        vec_row_it RowIt; // iterador da row atual da imagem original
        vec_rev_row_it New_RowIt; // iterador reverso da row atual da imagem rodada
        vec_pix_it pixelIt; // iterador dos pixeis da row atual da imagem original
        vec_pix_it New_pixelIt; // iterador dos pixeis da row atual da imagem rodada

        for (RowIt = pixel_matrix_.begin(); RowIt != pixel_matrix_.end() ; RowIt++){ // percorre as rows da imagem original
            New_RowIt = new_image.pixel_matrix_.rbegin(); // coloca o iterador das rows na última row da imagem rodada
            for (pixelIt = RowIt -> begin(); pixelIt != RowIt -> end(); pixelIt++) { // percorre os pixeis em cada row da imagem original
                New_pixelIt = New_RowIt->begin() + std::distance(pixel_matrix_.begin(), RowIt); // coloca o iterador dos pixeis na coluna correta. i.e: se está na 2a row da imagem original então tem de estar na 2a mais a esquerda coluna da nova imagem
                *New_pixelIt = *pixelIt; // copia o pixel 
                 New_RowIt++; // anda da útlima row até à primeira.
            }
            
        }

        *this = new_image;

    }

        /*

        for (int i = 0; i < height_; i++){
            for (int j = 0; j < width_; j++) {
                new_image.pixel_matrix_[width_-j-1][i] = pixel_matrix_[i][j];
            }
        }

        *this = new_image;
        

    }*/
    
    /* roda a imagem para a direita, copiando as rows de cima para baixo ,da imagem original para as colunas, da direita para 
    a esquerda, da nova imagem*/
   void Image::rotate_right() {

        Image new_image(height_,width_);

        vec_row_it RowIt; // iterador da row atual da imagem original
        vec_row_it New_RowIt; // iterador reverso da row atual da imagem rodada
        vec_pix_it pixelIt; // iterador dos pixeis da row atual da imagem original
        vec_rev_pix_it New_pixelIt; // iterador dos pixeis da row atual da imagem rodada

        for (RowIt = pixel_matrix_.begin(); RowIt != pixel_matrix_.end() ; RowIt++){ // percorre as rows da imagem original
            New_RowIt = new_image.pixel_matrix_.begin(); // coloca o iterador das rows na primeira row da imagem rodada
            for (pixelIt = RowIt -> begin(); pixelIt != RowIt -> end(); pixelIt++) { // percorre os pixeis em cada row da imagem original
                New_pixelIt = New_RowIt->rbegin() + std::distance(pixel_matrix_.begin(), RowIt); // coloca o iterador dos pixeis na coluna correta. i.e: se está na 2a row da imagem original então tem de estar na 2a coluna mais a direita da nova imagem a contar 
                *New_pixelIt = *pixelIt; // copia o pixel 
                 New_RowIt++; // anda da primeira  row até à útlima.
            }
            
        }

        *this = new_image;
 
    /*
        for (int i = 0; i < height_; i++){
            for (int j = 0; j < width_; j++) {
                new_image.pixel_matrix_[j][height_-i-1] = pixel_matrix_[i][j];
            }
        }

        *this = new_image;

   }*/

}
    // Função auxiliar para calcular os valores medianos RGB de uma determinada janela.
    // Calcula e devolve a mediana de um vector de rgb_values
    rgb_value Image::median_aux_cal(std::vector<rgb_value> med_vec) {
        size_t size = med_vec.size();   //tamanho do vector
        std::sort(med_vec.begin(), med_vec.end()); //ordena os valores do vector

        if (size % 2 == 1) return med_vec.at(size/2); // calculo da mediana
        else {
            rgb_value mid_1 = med_vec.at(size/2-1);
            rgb_value mid_2 = med_vec.at(size/2);
            
            /*for (auto c : med_vec) {
                std::cout << c << " ";
            }
            
            std::cout << "\n";
            */
            
            return (mid_1+mid_2)/2;

        }
        
    }

   
   
   /*é iterado através de indices cada pixel dentro de uma janela de tamanho fixo >3 
   são criados 3 vetores para acumular os valores RGB para depois com uma funcao auxiliar ser calculada a mediana para cada valor.
    numa nova imagem são guardados os novos valores dos pixeis da janela iterada
   */

  void Image::median_filter(int ws) {
    if (ws < 3 || ws % 2 == 0) return; // nao executa se nao for um valor valido.
    //double count = 0;

    Image new_image(width_,height_);

    int radius = ws / 2; // distancia do centro até aos limites da janela

    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            std::vector<rgb_value> m_red, m_green, m_blue; // criação de vetores para cada cor para calculo da sua mediana

            for (int l = i - radius; l <= i + radius; l++) { //itera sobre a janela de accao de um dado pixel
                for (int k = j - radius; k <= j + radius; k++) {
                    if (l >= 0 && l < height_ && k >= 0 && k < width_) {
                        m_red.push_back(pixel_matrix_[l][k].red()); // adiciona aos vetores o valor de R, G, B.
                        m_green.push_back(pixel_matrix_[l][k].green());
                        m_blue.push_back(pixel_matrix_[l][k].blue());
                    }
                }
            }

            /*é adicionada a matriz um novo pixel filtrado, com o auxilio de uma função que ordena o vetor e
            calcula a sua mediana*/

            new_image.pixel_matrix_[i][j].setRGB(median_aux_cal(m_red), median_aux_cal(m_green), median_aux_cal(m_blue));
            //count++;

        }
    }

    *this = new_image;
    
}
}   