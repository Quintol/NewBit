#include "TestEngine.h"
using namespace std;

nb::TestEngine::TestEngine()
{
	cout << "TestEngine()" << endl;
}

void nb::TestEngine::init()
{
	cout << "TestEngine init()" << endl;

	getCore()->gameStates.pushState( make_unique<TestGameState>() );

	return;
}

bool nb::TestEngine::update()
{
	return true;
}
