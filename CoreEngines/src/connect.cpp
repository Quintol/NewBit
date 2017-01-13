#include "TestEngine.h"
#include "RenderEngine.h"

using namespace std;

extern "C" {
	DLL_EXPORT void nbConnectCore( nb::CoreEngineManager* manager )
	{
		manager->addEngine( make_unique<nb::TestEngine>() );
		manager->addEngine( make_unique<nb::RenderEngine>() );
	}
}
