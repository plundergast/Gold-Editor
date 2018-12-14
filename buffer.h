#pragma once
#include <vector>
#include <string>

class buffer
{
public:
	inline std::string& line_at_cursor ();
	std::vector<std::string> lines = std::vector<std::string> ();
	std::string name = "Unnamed buffer";

	int width = 100;
	int height = 100;
	int x = 0;
	int y = 0;
private:
	int cursor_row  = 0; 
	int cursor_line = 0;
	bool render_cursor = false;
};