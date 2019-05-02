var message = require('./message_pb');
nano = require('nanomsg');

var sub = nano.socket('sub');
var addr = 'tcp://127.0.0.1:5555';
sub.connect(addr);

sub.on('data', function(buf) {
  // new message
  var message_data = new proto.message.Message.deserializeBinary(buf);

  for (i = 0; i < message_data.getIdList().length; i++) {
    console.log(message_data.getIdList()[i]);
  }
});
