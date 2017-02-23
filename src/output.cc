#include <vector>
#include <algorithm>
#include "caches.hh"
#include "endpoints.hh"
#include "requests.hh"
#include "sort_video.hh"

bool operator== (const Endpoint& a, const Endpoint& b)
{
  return a.id == b.id;
}

bool operator== (const Endpoint& a, const int b)
{
  return a.id == b;
}

bool compare_latency(Cache& a, Cache& b)
{
  return a.latency < b.latency;
}

void sort_latency_rec(Endpoint a)
{
  std::sort(a.caches.begin(), a.caches.end(), compare_latency);
}


void sort_latency(std::vector<Endpoint>& ep)
{
  for (auto it = ep.begin(); it != ep.end(); ++it)
  {
    sort_latency_rec(*it);
  }
}

void global_sort(std::vector<Request>& req, std::vector<Endpoint>& ep, std::vector<Video>& v)
{
  sort_request(req);
  sort_latency(ep);


  for (auto it = req.begin(); it != req.end(); ++it)
  {
    int j = 0;
    bool b = true;
    auto i = std::find(ep.begin(), ep.end(), (*it).endpoint_id);

    while (b)
    {
      if ((i->caches.begin() + j)->capacity > v[it->video_id].size)
        j++;
      else
      {
        (i->caches.begin() + j)->capacity -=  v[it->video_id].size;
        (i->caches.begin() + j)->out.push_back(v[it->video_id]);
        b = false;
      }
    }
  }
}

void insert_caches(std::vector<Cache>& out, std::vector<Endpoint>& eps)
{
  int done[1000] = { -1 };
  for (auto ep: eps)
  {
    for (auto cache: ep.caches)
    {
      if (done[cache.id] == -1)
      {
        out.push_back(cache);
      }
    }
  }
}
