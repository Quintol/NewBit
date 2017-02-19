#include "EntityManager.h"
using namespace std;

void nb::EntityManager::executeDeleteEntities()
{
	s_onDeleteEntities.call( m_toDelete );

	m_entities.remove_if( [&]( auto& el ) {
		for (auto it = m_toDelete.begin(); it != m_toDelete.end(); ++it)
		{
			if (*it == &el)
			{
				m_toDelete.erase( remove( m_toDelete.begin(), m_toDelete.end(), &el ) );
				el.destroy();
				return true;
			}
		}
		return false;
	} );

	if (m_toDelete.size() != 0)
	{
		throw exception::EntityDoesNotExistException();
	}
}

nb::Entity * nb::EntityManager::createEntity( std::vector<std::unique_ptr<Component>>&& components )
{
	Entity entity;
	for (auto& el : components)
		entity.addComponent( move( el ) );
	entity.init();

	m_entities.push_back( move( entity ) );

	Entity* en = &m_entities.back();
	s_onEntityCreated.call( en );
	return en;
}

void nb::EntityManager::deleteEntity( Entity * entity )
{
	m_toDelete.push_back( entity );
}

int nb::EntityManager::getEntityCount() const
{
	return m_entities.size();
}
