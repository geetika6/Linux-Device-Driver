cmd_/root/modules/hello-1.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /root/modules/hello-1.ko /root/modules/hello-1.o /root/modules/hello-1.mod.o
