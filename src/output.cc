#include <vector>
#include <algorithm>
#include "caches.hh"


bool operator== (const Endpoint& a, const Endpoint& b)
{
  return a.id_ == b.id_;
}

bool compare_latency(Endpoint& a, Endpoint& b)
{
  return a.latency < b.latency;
}

void sort_latency_rec(Endpoint a)
{
 std::sort(a.begin(), a.end(), compare_latency);
}


void sort_latency(std::vector<Endpoint>& ep)
{
  for (auto it = rq.begin(); it != rq.end(); ++it)
  {
    sort_latency_rec(*it);
  }
}

void global_sort(std::vector<Request>& req, std::vector<Endpoint>& ep)
{
  sort_request(req);
  sort_latency(ep);

  std::vector<Cache> vect_cache;

  for (auto it = req.begin(); it != req.end(); ++it)
  {
    auto i = std::find(ep.begin(), ep.end(), *it.endpoint_id);
    i.caches.begin();
  }
}
