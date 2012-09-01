#include "http.h"

int main( int argc, char **argv) {
  int sd; //Socket descriptor
  int fd; //File descriptor
  int port = 3000; //Socket port
  int opc = 1; // Socket option
 
  struct sockaddr_in direccion = {};
  //Type of socket created with socket()
  direccion.sin_family = AF_INET;
  direccion.sin_addr.s_addr = htonl( INADDR_ANY);
  //Define connection port
  direccion.sin_port = htons(port);

  sd = socket( PF_INET, SOCK_STREAM, 0); //Create socket
  if( -1 == sd) {
    perror( "socket");
    exit( EXIT_FAILURE);
  }
  
  //Set socket options -> SOL_SOCKET specifies options at level socket, SO_REUSEADDR specifies reuse local addresses
  setsockopt( sd, SOL_SOCKET, SO_REUSEADDR, &opc, sizeof opc);	

  //Bind a name to a socket
  if( bind( sd, ( struct sockaddr *) &direccion, sizeof direccion) < 0) {
    perror( "binding");
    exit( EXIT_FAILURE);
  }

  //Listen for new connections
  if( -1 == listen( sd, 5)) {
    perror( "listen");
    exit( EXIT_FAILURE);
  }
	
  while(1) {
  fd = accept( sd, NULL, 0); //Accept connection

  printf("Connected\n");
    // switch( fork( )) {
    // case 0: /* hijo */
    //   close( sd);

    //   char buff[ 256];
    //   //char requested_page[256];
    //   char page_buffer[ 256];
    //   char *get;
    //   char mje_404[] = "HTTP/1.1 404 Not Found\n";
    //   char mje_405[] = "HTTP/1.1 405 Method Not Allowed\n";
    //  // char mje_200[] = "HTTP/1.1 200 OK\n";
    //  // char mje_500[] = "HTTP/1.1 500 Internal Server Error\n";
    //   int pd, leidos, pleidos;
      
    //   /* read request */
    //   if( ( leidos = read( fd, buff, sizeof buff)) < 0 ) {
	   //    perror( "read en el socket");
	   //    close( fd);
	   //    exit( EXIT_FAILURE);
    //   }
      
    //   /* check method == get */
    //   get = parse_request( buff, leidos);
    //   if( NULL == get) {
	   //    write( fd, mje_405, sizeof mje_405);
	   //    close( fd);
	   //    exit( EXIT_SUCCESS);
    //   }

	   //    printf("get  tiene: %s",get);

    //    if( ( pd = open("index.html", O_RDONLY)) == -1) {
	   //    write( fd, mje_404, strlen( mje_404));
	   //    close( fd);
	   //    perror( "open");
	   //    exit( EXIT_SUCCESS);
    //   }

    //   pleidos = read (pd, page_buffer, sizeof page_buffer);
    //   do {
  	 //      write( fd, page_buffer, pleidos);
    //   }	while( ( pleidos = read( pd, page_buffer, sizeof page_buffer)) > 0);


    //   close( pd);// close( fd);
      
    //   exit( EXIT_SUCCESS);

    // case -1: /* errors on fork */
    //   close( fd);
    //   close( sd);
    //   perror( "fork");
    //   exit( EXIT_FAILURE);
    //   break;
      
    // default: // padre
    //   close( fd);
    //   break;
    // }
    
  }
  return 0;
}
