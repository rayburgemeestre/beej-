#include "beej.h"

int main() {
  beej::client client("localhost", 10000);
  client.connect();
  client.send("Hello ");
  client.send("world!\nHello world again!\n");
}
