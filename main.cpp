#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "ID3V1.h"

// A significant amount of this code is from my CS 010C professor Pat Miller. 

using namespace std;

int main() {
  // This is a constant char pointer that points to an array of chars. "mp3" can also be read as a string
  const char *mp3 = "Sample Music Files/80. Space Junk Galaxy.mp3";
  
  // f will be negative or 2 if the OS can't open the file. Otherwise, the integer f is used to refer to a table of files this process has opened, starting from 3.
  int f = ::open(mp3,O_RDONLY);
  cout << f << ' ' << sizeof(ID3v1) << endl;

  ID3v1 header;

  int n = ::read(f,&header,128);


  cout << n << endl;
  // cout << header.tag() << endl;
  // cout << header.title() << endl;

  // Why does outputting a 128 char array work the same as outputting a 3 char array? "properties" should have all 128 bytes from the file, and should output all of them.
  cout << header.properties << endl;
  
}
  