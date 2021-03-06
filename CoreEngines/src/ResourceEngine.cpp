#include "ResourceEngine.h"
using namespace std;
using namespace sf;
using namespace nb;

const std::string ResourceEngine::PATH_PACKAGES = "./Packages";

void nb::ResourceEngine::init()
{
	packages.initFromFolder( PATH_PACKAGES );
	packages.save();

	textures.init( packages );
}

bool nb::ResourceEngine::update()
{
	return true;
}
