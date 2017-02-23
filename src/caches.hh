#pragma once

class Cache
{
public:
   Cache(int id, int latency, int capacity)
    {
      this->id = id;
      this->latency = latency;
      this->capacity = capacity;
    }

   int id;
   int capacity;
   int latency;
};
