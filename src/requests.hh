#pragma once


class Request
{
public:
  Request(int nb_requests, int video_id, int endpoint_id)
    {
      this->nb_requests = nb_requests;
      this->video_id = video_id;
      this->endpoint_id = endpoint_id;
    }

  int nb_requests;
  int video_id;
  int endpoint_id;
};
