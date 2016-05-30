cmd_/root/modules/drv.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /root/modules/drv.ko /root/modules/drv.o /root/modules/drv.mod.o
