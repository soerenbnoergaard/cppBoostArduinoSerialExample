/** 
 * 1. Write command to serial port
 * 2. Read response from serial port
 * 3. Repeat
 */
#include <iostream>
#include <boost/asio.hpp> 
using namespace::boost::asio;  
using namespace std;

#define PORT "/dev/ttyUSB0"

// Base serial settings
serial_port_base::baud_rate BAUD(9600);
serial_port_base::flow_control FLOW( serial_port_base::flow_control::none );
serial_port_base::parity PARITY( serial_port_base::parity::none );
// serial_port_base::stop_bits STOP( serial_port_base::stop_bits::one );
serial_port_base::stop_bits STOP( serial_port_base::stop_bits::one );

int main(){
  io_service io;
  serial_port port( io, PORT );

  // Setup port - base settings
  port.set_option( BAUD );
  port.set_option( FLOW );
  port.set_option( PARITY );
  port.set_option( STOP );

  unsigned char input;
  char c;
  while(1){
    // Send -------------------------------------------------------------------
    // What to send
    cin >> input;

    // Output buffer
    unsigned char command[1] = {0};

    // Convert and send
    command[0] = static_cast<unsigned char>( input );
    write(port, buffer(command, 1));

    // Receive response -------------------------------------------------------
    read(port,buffer(&c,1));
    cout << c << endl;
  }

  return 0;
}
