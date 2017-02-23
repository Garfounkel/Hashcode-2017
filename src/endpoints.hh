#pragma once

#include <vector>
#include <iostream>
#include <tuple>
#include "caches.hh"

class Endpoint
{
public:
  Endpoint(int id, int datacenter_latency)
    {
      this->datacenter_latency = datacenter_latency;
      this->id = id;
    }

   void add_cache(int id, int ping)
    {
       caches.push_back(std::pair<int,int>(id,ping));
    }

  int id;
   std::vector<std::pair<int, int>> caches;
  int datacenter_latency; // 2 <= datacenter_latency <= 4000
};
