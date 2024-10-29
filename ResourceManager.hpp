#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
    ResourceManager() : data{new Resource()} {}  // konstruktor domyślny
    ResourceManager(const ResourceManager &rm)   // konstruktor kopiujący
    {
      data = new Resource();
      *data = *(rm.data);
    }
    ResourceManager& operator=(const ResourceManager &rm) // kopiujący operator przypisania
    {
      delete data;
      data = NULL;
      data = new Resource();
      *data = *(rm.data);
      return *this;
    }
    ResourceManager(ResourceManager&& rm) //konstruktor przenoszący
    {

    }
    ResourceManager& operator=(ResourceManager&& rm) //przenoszący operator przypisania
    {
      return *this;
    }
    ~ResourceManager() { delete data; }   //destruktor
    const double get() { return data->get(); }
    Resource* data;
};
