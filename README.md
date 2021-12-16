### Beej++

Based on https://beej.us/guide/bgnet/html/

This stuff was made in a hurry for a very simple use case (centralized logging over TCP).

- one server (receive only)
- multiple clients (send only)
- data transmitted are only strings


### Build

```
git clone https://github.com/rayburgemeestre/beej-plus-plus beej++
pushd beej++
make
sudo make install
```


### Server

Start server on port `10000`.

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

Connect to server on `localhost` port `10000`.

Then send a bunch of text..

```
#include "beej.h"

int main() {
  beej::client client("localhost", 10000);
  client.connect();
  client.send("Hello ");
  client.send("world!\nHello world again!\n");
}
```
