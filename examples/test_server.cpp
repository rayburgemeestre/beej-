#include "beej.h"

#include <iostream>

int main() {
  beej::server server(10000);
  server.on_line([](const std::string& line) {
    std::cout << "Received line: " << line;
  });
  server.run();
}
