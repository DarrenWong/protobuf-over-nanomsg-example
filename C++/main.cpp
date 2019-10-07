#include <iostream>
#include <netinet/in.h> /* For htonl and ntohl */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <nanomsg/nn.h>
#include <nanomsg/pubsub.h>

#include <message.pb.h>

using namespace std;

//init server
int server(const char *url) {
  int fd;
  /*  Create the socket. */
  fd = nn_socket(AF_SP, NN_PUB);
  if (fd < 0) {
    fprintf(stderr, "nn_socket: %s\n", nn_strerror(nn_errno()));
    return (-1);
  }

  /*  Bind to the URL.  This will bind to the address and listen
      synchronously; new clients will be accepted asynchronously
      without further action from the calling program. */

  if (nn_bind(fd, url) < 0) {
    fprintf(stderr, "nn_bind: %s\n", nn_strerror(nn_errno()));
    nn_close(fd);
    return (-1);
  }
  return fd;
}

int main(int argc, char *argv[]) {
  message::Message m;
  for (int i = 0; i < 10; i++) {
    m.add_id(i);
  }
  cout << "Hello Proto!" << endl;
  if (argc == 1) {
    int fd = server("tcp://127.0.0.1:5555");
    while (true) {
      int rc;
      message::Message m;
      for (int i = 0; i < 10; i++) {
        m.add_id(i);
      }
      size_t size = m.ByteSizeLong();
      char buff[size];
      m.SerializeToArray(buff, size);
      rc = nn_send(fd, buff, sizeof(buff), 0);
      if (rc < 0) {
        cout << "nn_send error" << endl;
      }
      sleep(1);
    }
  } else {
    cout << "Usage: ./protobuf_over_nanomsg <url>" << endl;
  }

  return 0;
}
