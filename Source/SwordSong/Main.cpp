#include "SwordSong/SwordSong.h"
#include "SwordSong/Engine.h"

using namespace SwordSong;

int main(int argc, char** argv) {
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Run();

	exit(EXIT_SUCCESS);
}