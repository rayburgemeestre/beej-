#pragma once

#include <string>

class socketbuffer {
public:
  socketbuffer();
  ~socketbuffer();

  virtual void append(const char *);
  virtual void append(const char *, size_t);

  const std::string &get();
  size_t length();

  bool has_line();
  std::string get_line();
  std::string get_raw();

  void gc();

protected:
  std::string buffer_;
  size_t index_;

  size_t gc_line_num_;
  size_t gc_every_;
};
