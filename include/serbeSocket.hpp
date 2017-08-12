#ifndef _SERBESOCKET_HPP_
#define _SERBESOCKET_HPP_

#include <common.hpp>
#include <netlib.hpp>

class serbeSocket {
   public:
	serbeSocket (SyncSocket *fd);
	~serbeSocket ();

	char readChar ();               // reads a char
	string readuntil (char until);  // reads until a specific char is found
	string readuntilskip (
	    char until);     // reads until a specific char is found. The character itself is skipped
	string read2end ();  // reads a string until there is no more data (\n\r)

	/** send
	 * Sends a full message to a socket
	 * @return 0 if OK, something else if error.
	 * ERROR CODES:
	 * -1 if socket is closed.
	 */
	int send (const void *message, size_t len);

   protected:
   private:
	SyncSocket *fd;
};

#endif