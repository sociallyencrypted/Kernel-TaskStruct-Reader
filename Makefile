obj-m += taskStructReader.o

PWD := $(CURDIR)
KDIR := /lib/modules/$(shell uname -r)/build

default:
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf *.o *.ko *.mod.c *.symvers *.order *.markers *.unsigned