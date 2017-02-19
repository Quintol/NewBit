#pragma once
#include "TestGameState.h"
#include "id.h"

namespace nb
{
	class TestEngine : public nb::CoreEngine
	{
	public:
		DLL_EXPORT TestEngine();

		DLL_EXPORT virtual void init( const CoreRef& coreRefs )override;

		DLL_EXPORT virtual bool update( const CoreRef& coreRefs )override;
	};
}
