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

void global_sort(std::vector<Request>& req, std::vector<Endpoint>& ep, std::vector<Video>& v, std::vector<Cache>& ch)
{
  sort_request(req);
  sort_latency(ep);


  for (auto it = req.begin(); it != req.end(); ++it)
  {
    int j = 0;
    bool b = true;
    auto i = std::find(ep.begin(), ep.end(), *it.endpoint_id);

    while (b)
    {
      if ((i.caches.begin() + j).capacity > v[*it.video_id].size)
        j++;
      else
      {
        (i.caches.begin() + j).capacity -=  v[*it.video_id].size;
        (i.caches.begin() + j).out.push_back(v[*it.video_id]);
        b = false;
      }
    }
  }
}
