#include "buffer.h"
#include "parser.h"

inline std::string& buffer::line_at_cursor ()
{
	return lines.at (cursor_line);
}
