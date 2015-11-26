#include "Scene.h"

Scene::~Scene( )
{
    for ( std::vector<ObjectBase*>::iterator it = this->Objects.begin( ); it != this->Objects.end( ); ++it )
        delete *it;
}

void Scene::AddObject( ObjectBase* object )
{
    if ( std::find( this->Objects.begin( ), this->Objects.end( ), object ) != this->Objects.end( ) )
        return;

    this->Objects.push_back( object );
}

const std::vector<ObjectBase*>& Scene::GetObjects( ) const
{
    return this->Objects;
}
