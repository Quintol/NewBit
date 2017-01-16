#pragma once
#include "InputEngine.h"
using namespace std;
using namespace sf;
using namespace nb;

void nb::InputEngine::init( const CoreRefs & coreRefs )
{
	auto* renderEngine = coreRefs.engines.getEngine<RenderEngine>();
	renderEngine->s_onEvent.connect_mem_fn_auto( &InputEngine::forwardSfEvent, *this );
}

bool nb::InputEngine::update( const CoreRefs & coreRefs )
{
	return true;
}

void nb::InputEngine::forwardSfEvent( const sf::Event & event )
{
	cout << event.type << endl;
}