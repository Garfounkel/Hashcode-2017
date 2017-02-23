#include <algorithm>
#include <vector>

void sort_request(std::vector<Request>& req)
{
  std::sort(req.begin(), req.end(), [](const Request& lhs, Request& rhs){ return lhs. < rhs.value; });
  }
}