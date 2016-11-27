#pragma once
#include "stdafx.h"

namespace nb
{
	namespace entity
	{
		namespace exception
		{
			class SystemAlreadyExistsException : public std::exception
			{
				const std::string m_message;
			public:
				DLL_EXPORT SystemAlreadyExistsException( const std::string& m_systemTypeName );

				DLL_EXPORT virtual const char* what()const override;
			};
		}
	}
}