#assemble boot.s file
as --32 src/boot.asm -o bin/boot.o

#compile kernel.c file
gcc -m32 -c bin/kernel.c -o bin/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

#linking the kernel with kernel.o and boot.o files
ld -m elf_i386 -T linker.ld bin/kernel.o bin/boot.o -o bin/MyOS.bin -nostdlib

#check MyOS.bin file is x86 multiboot file or not
grub-file --is-x86-multiboot bin/MyOS.bin

#building the iso file
mkdir -p bin/isodir/boot/grub
cp bin/MyOS.bin bin/isodir/boot/MyOS.bin
cp bin/grub.cfg bin/isodir/boot/grub/grub.cfg
grub-mkrescue -o bin/MyOS.iso bin/isodir

#run it in qemu
qemu-system-x86_64 -cdrom bin/MyOS.iso