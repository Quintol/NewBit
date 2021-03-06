#pragma once
#include "stdafx.h"

namespace nb
{
	namespace exception
	{
		class EntityAlreadyInitializedException : public std::runtime_error
		{
		public:
			DLL_EXPORT EntityAlreadyInitializedException();
		};
	}
}
