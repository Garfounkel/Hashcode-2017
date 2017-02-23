#pragma once

bool operator== (const Endpoint& a, const Endpoint& b);
bool operator== (const Endpoint& a, const int b);
bool compare_latency(Cache& a, Cache& b);
void sort_latency_rec(Endpoint a);
void sort_latency(std::vector<Endpoint>& ep);
void global_sort(std::vector<Request>& req, std::vector<Endpoint>& ep, std::vector<Video>& v);
void insert_caches(std::vector<Cache>& out, std::vector<Endpoint>& eps);


