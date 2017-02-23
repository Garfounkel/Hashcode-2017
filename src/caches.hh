#pragma once

class Cache
{
public:
  Cache(int id, int latency)
    {
      this->id = id;
      this->latency = latency;
    }

  int id;
  int latency;
};
