#include <fstream>
#include <vector>

#include "videos.hh"
#include "requests.hh"
#include "caches.hh"
#include "endpoints.hh"

int main()
{
   std::ifstream in;
   in.open("me_at_the_zoo.in");

   std::string tmp;
   in >> tmp;
   int nbr_video = atoi(tmp.c_str());
   in >> tmp;
   int nbr_endpoints = atoi(tmp.c_str());
   in >> tmp;
   int nbr_request = atoi(tmp.c_str());
   in >> tmp;
   int nbr_caches = atoi(tmp.c_str());
   in >> tmp;
   int nbr_cache_capacity = atoi(tmp.c_str());
   std::getline(in, tmp);
   std::vector<Video> list_vid;
   for (int i = 0; i < nbr_video; i++)
   {
      in >> tmp;
      int size_vid = atoi(tmp.c_str());
      list_vid.push_back(Video(i, size_vid));
   }
   std::getline(in, tmp);

   std::vector<Endpoint> list_endp;
   for (int i = 0; i < nbr_endpoints; i++)
   {
      in >> tmp;
      int ping_data = atoi(tmp.c_str());
      in >> tmp;
      int connected_endpoint = atoi(tmp.c_str());
      Endpoint ep(i, ping_data);
      std::getline(in, tmp);
      for (int j = 0; j < connected_endpoint; j++)
      {
         in >> tmp;
         int id = atoi(tmp.c_str());
         in >> tmp;
         int ping_cache = atoi(tmp.c_str());
         ep.add_cache(id, ping_cache);
         std::getline(in, tmp);
      }
      list_endp.push_back(ep);
   }

   std::vector<Request> list_request;
   for (int i = 0; i < nbr_request; i++)
   {
      in >> tmp;
      int id_vid = atoi(tmp.c_str());
      in >> tmp;
      int id_endp = atoi(tmp.c_str());
      in >> tmp;
      int req_vids = atoi(tmp.c_str());
      list_request.push_back(Request(i, id_vid, id_endp, req_vids));
      std::getline(in, tmp);
   }

}
