#include "sort_video.hh"
#include <algorithm>
#include <vector>

void sort_request(std::vector<Request>& req)
{
  std::sort(req.begin(), req.end(), [](const Request& lhs, Request& rhs){
        return lhs.nb_requests > rhs.nb_requests;
     });
}

void sort_req_video(std::vector<Request>& req)
{
  std::sort(req.begin(), req.end(), [](const Request& lhs, Request& rhs){
        return lhs.video_id > rhs.video_id;
     });
}

void merge_request(std::vector<Request>& req)
{
   sort_req_video(req);
   for (auto a = req.begin(); a != req.end(); ++a)
   {
      if (a->video_id == (a + 1)->video_id
          && a->endpoint_id == (a + 1)->endpoint_id)
      {
         a->nb_requests += (a+1)->nb_requests;
         req.erase(a+1);
      }
   }
}
