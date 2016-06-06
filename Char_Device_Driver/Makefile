INSTALLDIR= modules
ifneq ($(KERNELRELEASE),)
	obj-m := drv.o
	drv-objs := init.o exit.o dev_open.o dev_release.o trim_dev.o creat_scull.o dev_write.o

else
	KERNDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	@rm -rf $(INSTALLDIR)
	@mkdir $(INSTALLDIR)
	@mv *.ko *.mod.c *.o .*.cmd $(INSTALLDIR)

clean:
	rm -rf $(INSTALLDIR)

endif

