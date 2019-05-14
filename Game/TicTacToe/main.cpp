#include <SFML/Graphics.hpp>

#include <iostream>


//globals dimensions for window
int num_vertBox = 61, num_horzBox = 61;
int size = 16; //number of pixels
int w = size * num_horzBox; //background number of pixels in width
int h = size * num_vertBox; //background number of pixels in height
bool gameover = false;
int winner = 0;


//Functions to check for win & restart game
void checkWin();
void restart();


//Rectangles to correspond to each box of the board.
sf::IntRect topLeft(16,16,320,320);
sf::IntRect topMiddle(336,16,320,320);
sf::IntRect topRight(656,16,320,320);
sf::IntRect midLeft(16,336,320,320);
sf::IntRect midMiddle(336,336,320,320);
sf::IntRect midRight(656,336,320,320);
sf::IntRect botLeft(16,656,320,320);
sf::IntRect botMiddle(336,656,320,320);
sf::IntRect botRight(656,656,320,320);


sf::IntRect hello[] = {topLeft, topMiddle, topRight,
                       midLeft, midMiddle, midRight,
                       botLeft, botMiddle, botRight};



//Array stores whether a spot is open, or taken by a player
int gamestate[] = {0,0,0,0,0,0,0,0,0};

int playerturn = 1;



int main(){


    //Window that we can play game in
    sf::RenderWindow window(sf::VideoMode(w,h), "Tic-Tac-Toe", sf::Style::Close);


    //Textures load
    sf::Texture t1, t2, t3, t5;
    t1.loadFromFile("imagess/white2.png");
    t2.loadFromFile("imagess/red2.png");
    t3.loadFromFile("imagess/Morty.png");
    t5.loadFromFile("imagess/Rick_Sanchez.png");

    //Sprite has physical dimensions
    sf::Sprite sprite1(t1);
    sf::Sprite sprite2(t2);
    sf::Sprite sprite3(t3);
    sf::Sprite sprite5(t5);



    while (window.isOpen()){




        sf::Event e;

        //Check when the window is closed
        while(window.pollEvent(e))
        {

            if( e.type == sf::Event::Closed){
                window.close();
            }
            if( e.type == sf::Event::MouseButtonPressed && !gameover ){
                sf::Vector2<int> is = sf::Mouse::getPosition(window);

                for(int i = 0; i < 9; i++) {
                    if (hello[i].contains(is)) {

                        if (gamestate[i] == 0) {
                            gamestate[i] = playerturn;
                            checkWin();
                            playerturn = playerturn * -1;

                        }//end inside if

                        std::cout << "You pressed within square: " << i << std::endl;

                    }//end middle if
                }
            }

            else if( e.type == sf::Event::MouseButtonPressed && gameover ){


                sf::Vector2<int> press = sf::Mouse::getPosition(window);
                sf::IntRect restartButton(300.5, 685, 375, 94);

                if (restartButton.contains(press)) {
                        restart();
                }
            }
        }


        window.clear();//get rid of all frame

        //Draw Background
        for(int i = 0; i< num_horzBox; i++) {
            for (int j = 0; j < num_vertBox; j++) {


                if( i == 20 || i == 40 || j == 20 || j == 40 || i == 0 || j== 0 || i == 60 || j == 60 ){
                    sprite2.setPosition(i * size, j * size);
                    window.draw(sprite2);
                }


                else {
                    sprite1.setPosition(i * size, j * size);
                    window.draw(sprite1);
                }


            }

        }


        //Drawing
        for(int i = 0; i < 9; i++ ) {
            if (gamestate[i] == 1) {
                sprite5.setPosition(hello[i].left, hello[i].top);
                window.draw(sprite5);
            }
            else if(gamestate[i] == -1){
                sprite3.setPosition(hello[i].left, hello[i].top);
                window.draw(sprite3);
            }
        }

        if(gameover){
            sf::Font font;

            font.loadFromFile("OpenSans-Bold.ttf");
            sf::Text text;

            text.setFont(font);
            if(winner != 0){
                text.setString("Player " + std::to_string(winner) + "\n   Wins");
            }
            else{
                text.setString("Tie");
            }

            text.setCharacterSize(100);
            text.setFillColor(sf::Color::Red);

            text.setOutlineColor(sf::Color::Black);
            text.setOutlineThickness(10);
            //text.setPosition(w/2,h/2);
            text.setPosition(w/2 - text.getLocalBounds().width/2, h/2 - text.getLocalBounds().height/2);
            window.draw(text);

            text.setString("Restart");
            //text.setPosition(w/2, 2*h/3);
            text.setPosition(w/2 - text.getLocalBounds().width/2, 3*h/4 - text.getLocalBounds().height/2);
            window.draw(text);
        }

        window.display();
    }
    return 0;
}

void restart(){
    gameover = false;
    winner = 0;
    playerturn = 1;

    for(int i = 0; i < 9; i++){
        gamestate[i] = 0;
    }
}



void checkWin(){
    if((gamestate[0] != 0) && (gamestate[0] == gamestate[1]) && (gamestate[1] == gamestate[2]) ||
       (gamestate[3] != 0) && (gamestate[3] == gamestate[4]) && (gamestate[4] == gamestate[5]) ||
       (gamestate[6] != 0) && (gamestate[6] == gamestate[7]) && (gamestate[7] == gamestate[8]) ||
       (gamestate[0] != 0) && (gamestate[0] == gamestate[3]) && (gamestate[3] == gamestate[6]) ||
       (gamestate[1] != 0) && (gamestate[1] == gamestate[4]) && (gamestate[4] == gamestate[7]) ||
       (gamestate[2] != 0) && (gamestate[2] == gamestate[5]) && (gamestate[5] == gamestate[8]) ||
       (gamestate[0] != 0) && (gamestate[0] == gamestate[4]) && (gamestate[4] == gamestate[8]) ||
       (gamestate[2] != 0) && (gamestate[2] == gamestate[4]) && (gamestate[4] == gamestate[6])   ){

        gameover = true;
        winner = playerturn;

        if(winner == -1)
            winner = 2;

    }
    else{
        gameover = true;
        for(int i = 0; i < 9; i++){
            if(gamestate[i] == 0){
                gameover = false;
            }
        }
    }
}