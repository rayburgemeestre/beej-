### Beej++

Based on https://beej.us/guide/bgnet/html/

This stuff was made in a hurry ;)

* one server
* multiple clients
* clients send lines of strings only


### Build

```
make
```


### Server

```
#include "beej.h"

#include <iostream>

int main() {
  beej::server server(10000);
  server.on_line([](const std::string& line) {
    std::cout << "Received line: " << line;
  });
  server.run();
}
```

### Client

```
#include "beej.h"

int main() {
  beej::client client("localhost", 10000);
  client.connect();
  client.send("Hello ");
  client.send("world!\nHello world again!\n");
}
```
