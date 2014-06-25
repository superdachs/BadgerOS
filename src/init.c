#include "output.h"

void init(void)
{
  // Clear BIOS Messages
  cls();

  // Print Welcome Message
  kprintf("BADGER OS 0.1 Booting...");
  kprintf("OK");
}
