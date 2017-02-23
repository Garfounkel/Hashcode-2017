#pragma once

#include <vector>
#include <iostream>
#include "caches.hh"

class Endpoint
{
public:
  Endpoint(int id, int datacenter_latency)
    {
      this->datacenter_latency = datacenter_latency;
      this->id = id;
    }

  void add_cache(Cache cache)
    {
      caches.push_back(cache);
    }

  int id;
  std::vector<Cache> caches;
  int datacenter_latency; // 2 <= datacenter_latency <= 4000
};
