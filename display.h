#pragma once
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <memory>

#include "buffer.h"

class display : public olc::PixelGameEngine
{
public:
	display ();
	~display ();
	std::shared_ptr <buffer> current_buffer;
	std::vector<std::shared_ptr<buffer>> buffers;

protected:
	void render_buffer (buffer& buff);
	bool OnUserCreate () override;
	bool OnUserUpdate (float deltaTime) override;
};

