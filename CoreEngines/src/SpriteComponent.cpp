#include "SpriteComponent.h"
using namespace std;
using namespace sf;
using namespace nb;

void nb::SpriteComponent::onPositionChanged( const TransformationComponent & transform )
{
	m_sprite.setPosition( Vector2f( transform.getPosition() ) );
}

void nb::SpriteComponent::onSizeChanged( const TransformationComponent & transform )
{
	auto& texrect = m_sprite.getTextureRect();
	auto& scale = m_sprite.getScale();
	auto& newSize = transform.getSize();
	m_sprite.setScale( newSize.x / (texrect.width*scale.x), newSize.y / (texrect.height*scale.y) );
}

void nb::SpriteComponent::onRotationChanged( const TransformationComponent & transform )
{
	m_sprite.setRotation( transform.getRotation() );
}

void nb::SpriteComponent::init( const Entity & entity )
{
	auto transform = entity.getComponent<TransformationComponent>();
	transform->s_positionChanged.connect_mem_fn_auto( &SpriteComponent::onPositionChanged, *this );
	transform->s_sizeChanged.connect_mem_fn_auto( &SpriteComponent::onSizeChanged, *this );
	transform->s_rotationChanged.connect_mem_fn_auto( &SpriteComponent::onRotationChanged, *this );
}

void nb::SpriteComponent::destroy( const Entity & entity )
{
}

int nb::SpriteComponent::getZValue() const
{
	return m_zValue;
}

void nb::SpriteComponent::setZValue( int zValue )
{
	m_zValue = zValue;
}

void nb::SpriteComponent::setTexture( const sf::Texture & texture )
{
	m_sprite.setTexture( texture );
}

const sf::Sprite & nb::SpriteComponent::getSprite() const
{
	return m_sprite;
}
