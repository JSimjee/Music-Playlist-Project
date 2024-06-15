#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "ID3V1.h"

using namespace std;

int main() {
  // This is not a char pointer nor a char array like in struct ID3V1, it's a string pointer
  const char *mp3 = "/Sample Music Files/80. Space Junk Galaxy.mp3";
  
  // Is this O_RDONLY literally just a 0 value? 
  // So this fancy syntax about ::open and the parameters link to some strange function in /usr/include/x86_64-linux-gnu, this is just something you know from experience in industry?
  int f = ::open(mp3,O_RDONLY);
  cout << f << ' ' << sizeof(ID3v1) << endl;

  ID3v1 header;
  int n = ::read(f,&header,128);
  cout << n << endl;
  cout << header.tag() << endl;
  
}
  