BadgerOS
========

* Very simple os for educational purpose.

* To build install gcc and std headers and run make.
    #Debian
    apt-get install build-essential
    
    #Arch
    pacman -S base-devel

* For testing you can run this within qemu with:

  #Debian
  apt-get install qemu
  
  #Arch
  pacman -S qemu

* Run with
  qemu-system-x86_64 -kernel kernel
