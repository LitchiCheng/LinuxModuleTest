KDIR ?= /home/dar/imx8/seer-imx-linux-kernel
# KDIR ?= /home/dar/imx8/linux-toradex
ARCH ?= arm64
CROSS_COMPILE ?= aarch64-linux-gnu-
SOC ?= IMX8QM

kbuild:
	date
	make SOC=$(SOC) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=`pwd`

clean:
	make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=`pwd` clean
	rm -f *~ Module.symvers Module.markers modules.order

module_install:
	date
	scp softlock.ko sr@192.168.31.77:/home/sr

app:
	make -C app-demo

