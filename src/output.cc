#include <vector>
#include <algorithm>
#include "caches.hh"


bool compare_latency(Endpoint& a, Endpoint& b)
{
  return a.latency < b.latency;
}

void sort_latency_rec(Endpoint a)
{
 std::sort(a.begin(), a.end(), compare_latency);
}


void sort_latency(std::vector<Endpoint>& rq)
{
  for (auto it = rq.begin(); it != rq.end(); ++it)
  {
    sort_latency_rec(*it);
  }
}
