//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

//////Variables//////
Texture textureRed, textureYellow, textureBlue, textureChess;
Sprite spriteRed, spriteYellow, spriteBlue, spriteChess;

///Punto de entrada a la aplicación///
int main() {
    // Cargamos las texturas de los archivos, se pueden combinar los if para muchas llamadas a loadFromFile
    if (!textureRed.loadFromFile("cuad_red.png") ||
        !textureYellow.loadFromFile("cuad_yellow.png") ||
        !textureBlue.loadFromFile("cuad_blue.png") ||
        !textureChess.loadFromFile("chessb.png")) {
        std::cerr << "Error: No se pudo cargar uno o más archivos de imagen" << std::endl;
        return -1;
    }

    // Creamos la ventana
    sf::RenderWindow App(sf::VideoMode(800, 800, 32), "Cuadrado de Imagenes"); // sin tilde porque se muestran mal

    // Configuramos los sprites
    spriteRed.setTexture(textureRed);
    spriteYellow.setTexture(textureYellow);
    spriteBlue.setTexture(textureBlue);
    spriteChess.setTexture(textureChess);

    // Escalamos los sprites para que todos tengan el mismo tamaño (400x400)
    float targetSize = 400.0f;

    spriteRed.setScale(targetSize / textureRed.getSize().x, targetSize / textureRed.getSize().y);
    spriteYellow.setScale(targetSize / textureYellow.getSize().x, targetSize / textureYellow.getSize().y);
    spriteBlue.setScale(targetSize / textureBlue.getSize().x, targetSize / textureBlue.getSize().y);
    spriteChess.setScale(targetSize / textureChess.getSize().x, targetSize / textureChess.getSize().y);

    // Posicionamos los sprites para formar un cuadrado graaande
    spriteRed.setPosition(0, 0); // Esquina superior izquierda
    spriteYellow.setPosition(400, 0); // Esquina superior derecha
    spriteBlue.setPosition(0, 400); // Esquina inferior izquierda
    spriteChess.setPosition(400, 400); // Esquina inferior derecha

    // Loop principal
    while (App.isOpen())
    {
        // Procesamos los eventos
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();
        }

        // Limpiamos la ventana
        App.clear();

        // Dibujamos los sprites
        App.draw(spriteRed);
        App.draw(spriteYellow);
        App.draw(spriteBlue);
        App.draw(spriteChess);

        // Mostramos la ventana
        App.display();
    }
    return 0;
}