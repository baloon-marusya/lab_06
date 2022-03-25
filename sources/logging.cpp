// Copyright 2021 Your Name <your_email>

#include <logging.hpp>

void set_logs(size_t val){
  auto trace_log = logs::add_file_log(
      keywords::file_name = ****************,
      keywords::rotation_size = val*1024*1024,
      keywords::format = "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  trace_log->set_filter(logs::trivial::severity >= logs::trivial::trace);
  auto info_log = boost::log::add_file_log(
      keywords::file_name = ****************,
      keywords::rotation_size = val*1024*1024,
      keywords::format = "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  info_log->set_filter(logs::trivial::severity >= logs::trivial::info);
  auto console_log = logs::add_console_log(
      std::clog,
      keywords::format = "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  console_log->set_filter(logs::trivial::severity >= logs::trivial::trace);
}
