#pragma once
#include "stdafx.h"

namespace nb
{
	namespace entity
	{
		namespace exception
		{
			class EntityDoesNotExistException : public std::runtime_error
			{
			public:
				DLL_EXPORT EntityDoesNotExistException();
			};
		}
	}
}