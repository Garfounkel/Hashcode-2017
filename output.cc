#include <vector>
#include <algorithm>
#include "caches.hh"

void sort_latency_rec(Endpoint)
{
  for (auto it = 
}

void sort_latency(std::vector<Endpoint>& rq)
{
  for (auto it = rq.begin(); it != rq.end(); ++it)
  {
    sort_latency_rec(*it);
  }
}
