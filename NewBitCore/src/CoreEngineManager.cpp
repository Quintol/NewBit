#include "CoreEngineManager.h"
using namespace std;
using namespace experimental;

namespace nb
{
	void nb::CoreEngineManager::loadFromFolder( std::string pathToFolder )
	{
#ifdef _WIN32
		for( auto& directoryEntry : filesystem::recursive_directory_iterator( pathToFolder ) )
		{
			auto path = directoryEntry.path();
			auto extension = path.extension().string();
			//make extension lowercase
			std::transform( begin( extension ), end( extension ), begin( extension ), ::tolower );
			if( extension == ".dll" )
			{
				HMODULE libraryHandle = LoadLibrary( path.string().c_str() );
				auto connectFunctionPtr = GetProcAddress( libraryHandle, "nbConnectCore" );
				if( connectFunctionPtr )
				{
					std::function<connectFunctionType> connectFuntion( reinterpret_cast<connectFunctionType*>( connectFunctionPtr ) );
					connectFuntion( this );
				}
			}
		}
#else
#error
#endif
	}

	void nb::CoreEngineManager::initEngines( const CoreRefs& coreRefs )
	{
		for( auto& el : m_enginesVector )
			el->init( coreRefs );
	}

	bool nb::CoreEngineManager::update( const CoreRefs& coreRefs )
	{
		bool continueRunning = true;
		for( auto& el : m_enginesVector )
			if( !el->update( coreRefs ) )
				continueRunning = false;
		return continueRunning;
	}
}
