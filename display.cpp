#include "display.h"
#include "parser.h"
#include <algorithm>

display::display ()
{
}

display::~display ()
{
}

void display::render_buffer (buffer & buff)
{
	
	int x_offset = std::to_string (buff.lines.size ()).size () * 8 + (buff.x * 8);
	int y_offset = buff.y * 8;
	
	FillRect (x_offset - 8, 0 + y_offset, 8, buff.height * 8, olc::Pixel (100, 100, 100));

	for (int line = 0; line < std::min<int>(buff.lines.size (),buff.height); ++line)
	{
		DrawString (buff.x * 8, line * 8 + y_offset, std::to_string (line), olc::DARK_BLUE);
		for (const auto& token : parse (buff.lines.at (line)))
		{
			olc::Pixel color = olc::BLACK;
			switch (token.type)
			{
				case Token::Type::Keyword:
					color = olc::DARK_CYAN;
					break;
				case Token::Type::Operator:
					color = olc::DARK_MAGENTA;
					break;
				case Token::Type::Branching:
					color = olc::DARK_BLUE;
					break;
				case Token::Type::Looping:
					color = olc::RED;
					break;
				case Token::Type::Built_In_Function:
					color = olc::DARK_YELLOW;
					break;
				case Token::Type::Type:
					color = olc::GREY;
					break;
				case Token::Type::Number:
					color = olc::DARK_RED;
					break;
			}
			DrawString (token.location * 8 + x_offset, line * 8 + y_offset, token.text, color);
		}
	}
	
	DrawString (buff.x * 8 + (buff.width * 8) - buff.name.size () * 8, buff.y * 8, buff.name, olc::DARK_RED);
	DrawRect (buff.x * 8, buff.y * 8, buff.width * 8, buff.height * 8, olc::BLACK);
}

bool display::OnUserCreate ()
{
	return true;
}

bool display::OnUserUpdate (float deltaTime)
{
	Clear (olc::WHITE);
	for(auto& buff : buffers)
	render_buffer (*buff);
	
	return true;
}
