#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
    ResourceManager() : data{new Resource()} {}  // konstruktor domyślny
    ResourceManager(const ResourceManager &rm) : data{rm.data} {}   // konstruktor kopiujący
    ResourceManager& operator=(const ResourceManager &rm) // kopiujący operator przypisania
    {
      if(this == &rm) {return *this;}
      delete data;
      data = NULL;
      data = rm.data;
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
