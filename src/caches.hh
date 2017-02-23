#pragma once

#include <vector>

class Cache
{
public:
   Cache(int id, int latency, int capacity)
    {
      this->id = id;
      this->latency = latency;
      this->capacity = capacity;
    }

  int capacity;
  int id;
  int latency;
  std::vector<Video> out;
};
