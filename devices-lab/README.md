# An xv6 Device Driver

In this tutorial assignment you will create a random number generator QEMU
device and use that to generate random numbers in xv6.

## QEMU Device

QEMU device must be built in-tree, so clone it from github.com/qemu/qemu.

Packages needed to build qemu

python3-venv ninja-build pkg-config libglib2.0-dev libpixman-1-dev flex bison
 
../configure --target-list=riscv64-softmmu --disable-sdl --disable-gtk

make -j`nproc`
./qemu-system-riscv64 -nographic

riscv64-unknown-elf-gcc    -c -o kernel/entry.o kernel/entry.S
