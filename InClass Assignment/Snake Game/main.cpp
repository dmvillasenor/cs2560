#include <SFML/Graphics.hpp>
#include <time.h>

/*
 * CHANGES:
 *
 * Made Fruit Red, and Second Snake green
 *
 * Added:
 *
 * Snake2
 * move2
 * direction2, and snake_length2
 * Made delay variable global
 * Texture 4 and Sprite 4 for second snake
 *
 */

//globals dimensions for window
int num_vertBox = 30, num_horzBox = 20;
int size = 16; //number of pixels
int w = size * num_horzBox; //background number of pixels in width
int h = size * num_vertBox; //background number of pixels in height

//Create the Snake
int direction, snake_length = 4;
int direction2, snake_length2 = 4;



//Maximum Snake Size
struct Snake{
    int x,y;

}s[100];

//Snake 2 for player 2
struct Snake2{
    int x,y;

}s2[100];

struct Fruit{
    int x, y;
}food;

//Made Delay global to be used by both moves
float delay = 0.1f;

void move(){

    for(int i = snake_length; i>0; --i){
        s[i].x = s[i-1].x;
        s[i].y = s[i-1].y;
    }
    //Head of snake, s[0] depends on direction user inputs

    //if user presses up
    if(direction == 0)
        s[0].y -= 1;

    //if user press down
    if(direction == 1)
        s[0].y += 1;

    if(direction == 2)
        s[0].x -= 1;

    if(direction == 3)
        s[0].x += 1;

    if(((s[0].x) == food.x) && ((s[0].y) == food.y)){
        snake_length++;
        delay = delay - 0.005;

        food.x = rand() % num_horzBox;
        food.y = rand() % num_vertBox;

    }

    if (s[0].x > num_horzBox)
        s[0].x = 0;
    if (s[0].x < 0 )
        s[0].x = num_horzBox;

    if (s[0].y > num_vertBox)
        s[0].y = 0;
    if (s[0].y < 0)
        s[0].y = num_vertBox;

    for (int i = 1; i < snake_length; i++){
        if (s[0].x == s[i].x && s[0].y == s[i].y)
            snake_length = i;
    }

}
void move2(){

    for(int i = snake_length2; i>0; --i){
        s2[i].x = s2[i-1].x;
        s2[i].y = s2[i-1].y;
    }
    //Head of snake, s[0] depends on direction user inputs

    //if user presses up
    if(direction2 == 0)
        s2[0].y -= 1;

    //if user press down
    if(direction2 == 1)
        s2[0].y += 1;

    if(direction2 == 2)
        s2[0].x -= 1;

    if(direction2 == 3)
        s2[0].x += 1;

    if(((s2[0].x) == food.x) && ((s2[0].y) == food.y)){
        snake_length2++;
        delay = delay - 0.005;

        food.x = rand() % num_horzBox;
        food.y = rand() % num_vertBox;

    }

    if (s2[0].x > num_horzBox)
        s2[0].x = 0;
    if (s2[0].x < 0 )
        s2[0].x = num_horzBox;

    if (s2[0].y > num_vertBox)
        s2[0].y = 0;
    if (s2[0].y < 0)
        s2[0].y = num_vertBox;

    for (int i = 1; i < snake_length2; i++){
        if (s2[0].x == s2[i].x && s2[0].y == s2[i].y)
            snake_length2 = i;
    }

}

int main(){

    srand(time(0));

    //Window that we can play game in
    sf::RenderWindow window(sf::VideoMode(w,h), "Snake Game");

    //Textures load
    sf::Texture t1, t2, t3, t4;
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/red.png");
    t4.loadFromFile("images/green.png");

    //Sprite has physical dimensions
    sf::Sprite sprite1(t1);
    sf::Sprite sprite2(t2);
    sf::Sprite sprite3(t3);
    sf::Sprite sprite4(t4);

    food.x = 10;
    food.y = 10;

    sf::Clock clock;
    float timer = 0.0f;

    while (window.isOpen()){

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        sf::Event e;

        //Check when the window is closed
        while(window.pollEvent(e))
        {
            if( e.type == sf::Event::Closed){
                window.close();
            }
        }

        //Control for snake by user
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction = 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction = 2;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction = 3;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction2 = 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction2 = 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction2 = 2;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction2 = 3;

        if(timer > delay){
            timer = 0;//reset timer
            move();
            move2();//move Snake one forward
        }

        window.clear();//get rid of all frame

        //Draw Background

        for(int i = 0; i< num_horzBox; i++) {
            for (int j = 0; j < num_vertBox; j++) {
                sprite1.setPosition(i * size, j * size);
                window.draw(sprite1);
            }
        }

        //Then Draw snake otherwise background will be drawn over snake
        for(int i = 0; i < snake_length; i++)
        {
            sprite2.setPosition(s[i].x*size, s[i].y*size);
            window.draw(sprite2);
        }

        for(int i = 0; i < snake_length2; i++)
        {
            sprite4.setPosition(s2[i].x*size, s2[i].y*size);
            window.draw(sprite4);
        }

        sprite3.setPosition(food.x*size, food.y*size);
        window.draw(sprite3);


        window.display();

    }

    return 0;
}