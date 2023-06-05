KDIR ?= /home/dar/imx8/seer-imx-linux-kernel
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
	scp imx-rpmsg-com.ko root@192.168.15.227:/home/root/safe-module/

app:
	make -C app-demo

