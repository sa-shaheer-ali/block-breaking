#include <SFML/Graphics.hpp>
#include <time.h>

int main() {
	srand(time(0));
	
	sf::RenderWindow window(sf::VideoMode(520,450), "game");
	window.setFramerateLimit(60);
	sf::Texture t1, t2, t3, t4;
	t1.loadFromFile("images/block01.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/ball.png");
	t4.loadFromFile("images/paddle.png");

	sf::Sprite background(t2), ball(t3), paddle(t4);
	
	paddle.setPosition(300,400);


	sf::Sprite block[1000];
	int n = 0;

	for (int i = 1; i <= 10; i++)
	{
		for (int j =1; j <=10; j++) {
			block[n].setTexture(t1);
			
			block[n].setPosition(i * 43, j * 20);
			n++;
		}

	}

	
	int dx=6;
	int dy=3;
	int x=300;
	int y=300;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


		}

		x += dx;
		for (size_t i = 0; i < n; i++)
		{

		if (sf::FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()))
		{
			block[i].setPosition(-100, 0);
			dx = -dx;

		}
		}
		y += dy;
		for (size_t i = 0; i < n; i++)
		{
			if (sf::FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
			{block[i].setPosition(-100, 0); dy = -dy;
		}}

	if (x<0|| x>520)
	{
		dx = -dx;

	}
	if ( y<0)
	{
		
	
		dy = -dy;
	
	}
	if (y > 450)
	{
		x = 300;
		y = 300;
		dy = 5;
		dx = 6;
		dy = -dy;


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		paddle.move(-6, 0);

	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		paddle.move(6,0);

	}
	if (sf::FloatRect(x, y, 12, 12).intersects(paddle.getGlobalBounds()))
		dy =-(rand() %5+2);
	ball.setPosition(x, y);

	


	window.clear();
	window.draw(background);
	window.draw(paddle);
	//window.draw(ball);
	for (size_t i = 0; i < 100; i++)
	{
		window.draw(ball);

	}
	for (size_t i = 0; i < n; i++)
	{
		window.draw(block[i]);

	}
	window.display();


	}

	
	return 0;
}