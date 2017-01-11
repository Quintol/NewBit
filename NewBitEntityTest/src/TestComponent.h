#include "stdafx.h"

class TestComponent : public nb::Component
{
public:
	TestComponent();

	virtual void init( const nb::Entity& entity ) override;
	virtual void destroy( const nb::Entity& entity ) override;

	bool has_init = false;
};
