#pragma once

#include <vector>
#include "videos.hh"

class Cache
{
  public:
    Cache(int id, int latency, int capacity)
    {
      this->id = id;
      this->latency = latency;
      this->capacity = capacity;
    }

    std::size_t capacity;
    int id;
    int latency;
    std::vector<Video> out;
};
