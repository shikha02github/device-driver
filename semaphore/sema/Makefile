obj-m := sema.o 

KERNDIR=/lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
PWD:=$(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	gcc -o read read.c
	gcc -o write1 write1.c
	gcc -o write2 write2.C

clean:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules
	rm read write1 write2