//
// Created by ilya on 22.03.2022.
//

#ifndef INCLUDE_JSON_CREATOR_HPP_
#define INCLUDE_JSON_CREATOR_HPP_

#include <ctime>
#include <fstream>
#include <mutex>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <iostream>

using json = nlohmann::json;

struct json_data{
  time_t timestamp;
  std::string hash;
  std::string data;
};

class json_creator{
 private:
  json data;
  mutable std::mutex mut;

 public:
  json_creator() = default;
  ~json_creator() = default;
  json_creator(const json_creator& val) = delete;
  json_creator& operator=(const json_creator& val) = delete;
  void add_item(const json_data& val);
  void save_json(const std::string& path) const;
  bool is_empty() const;
};

#endif  // INCLUDE_JSON_CREATOR_HPP_
