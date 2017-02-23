#pragma once

#include <iostream>

class Video
{
public:
  Video(std::size_t id, std::size_t size)
    {
      this->id = id;
      this->size = size;
    }

  std::size_t id;
  std::size_t size;
};
