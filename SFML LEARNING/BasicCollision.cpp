#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

std::string color_str{ "White" };

int color_num{ 0 };

int size = 15;

void menu_and_show()
{
	std::cout << "----------------------Controls----------------------\nLeft mouse button - draw\nRight mouse button - erase\nShift - change color\nUp arrow - make the brush bigger\nDown arrow - make the brush smaller\nC - clear\n----------------------Colors----------------------\nWhite\nYellow\nRed\nMagenta\nGreen\nCyan\nBlue\nBlack\n----------------------Size of brushes----------------------\n1 to 1000\n";
	std::cout << "------------------------------------------------------------------\nCurrent size: " << size << "\nCurrent color: " << color_str << std::endl;
	
}

int main()
{


	sf::Color color;

	color = sf::Color::White;


	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Painting", sf::Style::Fullscreen | sf::Style::Close);
	window.setFramerateLimit(120);

	window.setView(window.getDefaultView());

	menu_and_show();

	std::vector<sf::CircleShape> pixels;

	std::vector<sf::CircleShape> delete_pixels;

	bool leftButtonDown = false;

	bool rightButtonDown = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					leftButtonDown = true;
				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					rightButtonDown = true;
				}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					leftButtonDown = false;
				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					rightButtonDown = false;
				}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					if (size <= 1000)
					{ 
						size++;
						system("cls");
						menu_and_show();
					}
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					if (size >= 0)
					{
						size--;
						system("cls");
						menu_and_show();
					}
				}
				if (event.key.code == sf::Keyboard::LShift)
				{
					color_num++;
					if (color_num == 1)
					{
						color = sf::Color::White;
						color_str = "White";
						system("cls");
						menu_and_show();
					}
					else if (color_num == 2)
					{
						color = sf::Color::Yellow;
						color_str = "Yellow";
						system("cls");
						menu_and_show();
					}
					else if (color_num == 3)
					{
						color = sf::Color::Red;
						color_str = "Red";
						system("cls");
						menu_and_show();
					}
					else if (color_num == 4)
					{
						color = sf::Color::Magenta;
						color_str = "Magenta";
						system("cls");
						menu_and_show();
					}
					else if (color_num == 5)
					{
						color = sf::Color::Green;
						color_str = "Green";
						system("cls");
						menu_and_show();
					}
					else if (color_num == 6)
					{
						color = sf::Color::Cyan;
						color_str = "Cyan";
						system("cls");
						menu_and_show();
					}
					else if (color_num == 7)
					{
						color = sf::Color::Blue;
						color_str = "Blue";
						system("cls");
						menu_and_show();
					}
					else
					{
						color_num = 0;
						color = sf::Color::Black;
						color_str = "Black";
						system("cls");
						menu_and_show();
					}
				}
				if (event.key.code == sf::Keyboard::C)
				{
					pixels.clear();
					delete_pixels.clear();
				}
			}
		}

		if (leftButtonDown)
		{
			sf::CircleShape pixel(size);
			pixel.setFillColor(color);
			sf::Vector2i mousePos = sf::Mouse::getPosition(window) - sf::Vector2i(size, size);
			sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
			pixel.setPosition(worldPos);
			pixels.push_back(pixel);
		}

		if (rightButtonDown)
		{
			sf::CircleShape pixel(size);
			pixel.setFillColor(sf::Color::Black);
			sf::Vector2i mousePos = sf::Mouse::getPosition(window) - sf::Vector2i(size, size);
			sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);
			pixel.setPosition(worldPos);
			pixels.push_back(pixel);
		}

		window.clear();
		for (auto pixel : pixels)
		{
			window.draw(pixel);
		}
		for (auto delete_pixel : delete_pixels)
		{
			window.draw(delete_pixel);
		}
		window.display();
	}
}