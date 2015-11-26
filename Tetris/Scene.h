#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__
#include <vector>
#include "ObjectBase.h"

class Scene
{
public:
    Scene( ) : Objects( std::vector<ObjectBase*>( ) ) {};
    ~Scene( );

    void AddObject( ObjectBase* object );
    const std::vector<ObjectBase*>& GetObjects( ) const;

private:
    std::vector<ObjectBase*> Objects;
};

#endif