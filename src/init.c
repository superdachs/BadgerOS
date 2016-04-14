#include "output.h"
#include <stdio.h>

void init(void)
{
  // Clear BIOS Messages
  cls();

  // Print Welcome Message
  kprintf("BADGER OS 0.1 Booting...");
  
  // init control vars
  // termination var for exit main loop
  int terminate = 0;
  

  // Start Main Loop
  while(terminate == 0) {
  
  
      // stop loop
      terminate = 1;

  
  }
}
