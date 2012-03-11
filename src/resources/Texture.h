#pragma once
#include <SDL\SDL.h>
#include "ResourceBase.h"
#include "vec.h"

class vTextureResource : public vResource<SDL_Surface*>
{
public:
    vTextureResource(SDL_Surface* const &res);
    ~vTextureResource();

    virtual bool IsValid() const;

    vec3 GetSize() const;

protected:
};

class cTexture
{
public:
    cTexture(vTextureResource *res);

    SDL_Surface *Get() const;
    vTextureResource *GetRawResource() const { return m_Resource; }

    vec3 GetSize() const { return GetRawResource() ? GetRawResource()->GetSize() : vec3::ZERO; }

    void Release() { delete this; }

protected:

    vTextureResource *m_Resource;
};