#include "display.h"

int main ()
{
	buffer buff = buffer ();
	buff.lines.push_back ("def foo():");
	buff.lines.push_back ("	bar()");
	buff.lines.push_back ("foo()");


	display surface;

	if (surface.Construct (640, 480, 1, 1))
	{
		buff.height = (surface.ScreenHeight () / 2) / 8;
		surface.buffers.push_back(std::make_shared<buffer> (buff));
		surface.buffers.at (0)->width = (surface.ScreenWidth() / 2) / 8;
		surface.buffers.push_back(std::make_shared<buffer> (buff));
		surface.buffers.at (1)->width = (surface.ScreenWidth() / 2) / 8;
		surface.buffers.at (1)->x = (surface.ScreenWidth() / 2) / 8;


		surface.buffers.push_back (std::make_shared<buffer> ());
		surface.buffers.at (2)->lines.push_back ("Lorem ipsum dolor sit amet, consectetur adipiscing elit,");
		surface.buffers.at (2)->lines.push_back ("sed do eiusmod tempor incididunt ut labore et dolore magna aliqua");
		surface.buffers.at (2)->lines.push_back ("Ut enim ad minim veniam, quis nostrud");
		surface.buffers.at (2)->width = surface.ScreenWidth () / 8;
		surface.buffers.at (2)->height = (surface.ScreenHeight() / 8) / 2;
		surface.buffers.at (2)->y = (surface.ScreenHeight () / 2) / 8;

		surface.current_buffer = surface.buffers.at(0);
		
		surface.Start ();
		return EXIT_SUCCESS;
	}
	else return EXIT_FAILURE;
}