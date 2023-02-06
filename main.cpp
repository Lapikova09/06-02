#include <SFML/Graphics.hpp>
#include "settings.h"
#include "roadObj.h"

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
		WINDOW_TITLE,
		Style::Titlebar | Style::Close);
	window.setFramerateLimit(FPS);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2,0 });

	RoadObj road;
	roadObjInit(road, ROAD_POS, "road.jpg");
	RoadObj grass;
	roadObjInit(grass, GRASS_POS, "grass.jpg");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		roadObjUpdate(grass);
		roadObjUpdate(road);

		window.clear();
		roadObjDraw(window, grass);
		roadObjDraw(window,road);
		window.display();
	}

	return 0;
}