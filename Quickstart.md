### Getting the code ###
The code can either be downloaded through mercurial or directly from the **Downloads** tab
  * hg clone https://sbc9261-uboot-uip-ipv6.googlecode.com/hg/ sbc9261-uboot-uip-ipv6
```
[srini@localhost demo]# pwd
/tmp/demo
[root@localhost demo]# hg clone https://sbc9261-uboot-uip-ipv6.googlecode.com/hg/ sbc9261-uboot-uip-ipv6
requesting all changes
adding changesets
adding manifests
adding file changes
added 4 changesets with 4499 changes to 4466 files
4459 files updated, 0 files merged, 0 files removed, 0 files unresolved
[srini@localhost demo]# ls

```
  * http://sbc9261-uboot-uip-ipv6.googlecode.com/files/sbc9261-uboot-uip-ipv6-1.1.5.tar.bz2

### Compiling the code ###

  * Download the crosscompiler from http://sbc9261-uboot-uip-ipv6.googlecode.com/files/arm-linux-gcc-3.4.5-glibc-2.3.6-linux.tar.bz2 and untar it
```
[srini@localhost compiler]# pwd
/tmp/demo/compiler
[srini@localhost compiler]# wget http://sbc9261-uboot-uip-ipv6.googlecode.com/files/arm-linux-gcc-3.4.5-glibc-2.3.6-linux.tar.bz2
--21:30:22--  http://sbc9261-uboot-uip-ipv6.googlecode.com/files/arm-linux-gcc-3.4.5-glibc-2.3.6-linux.tar.bz2
           => `arm-linux-gcc-3.4.5-glibc-2.3.6-linux.tar.bz2'
Resolving sbc9261-uboot-uip-ipv6.googlecode.com... 74.125.155.82
Connecting to sbc9261-uboot-uip-ipv6.googlecode.com|74.125.155.82|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 39,162,493 (37M) [application/x-bzip2]

100%[=================================================================================================================================>] 39,162,493   421.74K/s    ETA 00:00

21:32:13 (346.10 KB/s) - `arm-linux-gcc-3.4.5-glibc-2.3.6-linux.tar.bz2' saved [39162493/39162493]

[srini@localhost compiler]#
[srini@localhost compiler]# tar -xvjf arm-linux-gcc-3.4.5-glibc-2.3.6-linux.tar.bz2
```
  * Change 'crosscmpincdir' in config.mk to point to the include directory of the compiler to be used
```
[srini@localhost sbc9261-uboot-uip-ipv6]# pwd
/tmp/demo/sbc9261-uboot-uip-ipv6
[srini@localhost sbc9261-uboot-uip-ipv6]# vim config.mk
```
> > So in case of the above example, the 'crosscmpincdir' would be edited as shown below
```
gccincdir := $(shell $(CC) -print-file-name=include)
crosscmpincdir := /tmp/demo/compiler/usr/crosstool/gcc-3.4.5-glibc-2.3.6/arm-linux/arm-linux/include
uipincdir := $(TOPDIR)/net/uip-1.0/uip

```

  * Configuring and compiling
```
[srini@localhost sbc9261-uboot-uip-ipv6]# pwd
/tmp/demo/sbc9261-uboot-uip-ipv6
[srini@localhost sbc9261-uboot-uip-ipv6]# make sbc9261_config_uip
Configuring for sbc9261_config_uip board...
... with uip stack enabled
[srini@localhost sbc9261-uboot-uip-ipv6]# make
```
> > So in case of the above example, on successful compilation, you should find u-boot.bin under /tmp/demo/sbc9261-uboot-uip-ipv6
```
make[1]: Leaving directory `/tmp/demo/sbc9261-uboot-uip-ipv6/net/uip-1.0/uip'
UNDEF_SYM=`arm-linux-objdump -x lib_generic/libgeneric.a board/sbc9261/libsbc9261.a cpu/arm926ejs/libarm926ejs.a cpu/arm926ejs/at91sam9261/libat91sam9261.a lib_arm/libarm.a fs/cramfs/libcramfs.a fs/fat/libfat.a fs/fdos/libfdos.a fs/jffs2/libjffs2.a fs/reiserfs/libreiserfs.a fs/ext2/libext2fs.a net/libnet.a disk/libdisk.a rtc/librtc.a dtt/libdtt.a drivers/libdrivers.a drivers/nand/libnand.a drivers/nand_legacy/libnand_legacy.a drivers/sk98lin/libsk98lin.a post/libpost.a post/cpu/libcpu.a common/libcommon.a net/uip-1.0/uip/libuip.a |sed  -n -e 's/.*\(__u_boot_cmd_.*\)/-u\1/p'|sort|uniq`;\
                cd /tmp/demo/sbc9261-uboot-uip-ipv6 && arm-linux-ld -Bstatic -T /tmp/demo/sbc9261-uboot-uip-ipv6/board/sbc9261/u-boot.lds -Ttext 0x23f00000  $UNDEF_SYM cpu/arm926ejs/start.o \
                        --start-group lib_generic/libgeneric.a board/sbc9261/libsbc9261.a cpu/arm926ejs/libarm926ejs.a cpu/arm926ejs/at91sam9261/libat91sam9261.a lib_arm/libarm.a fs/cramfs/libcramfs.a fs/fat/libfat.a fs/fdos/libfdos.a fs/jffs2/libjffs2.a fs/reiserfs/libreiserfs.a fs/ext2/libext2fs.a net/libnet.a disk/libdisk.a rtc/librtc.a dtt/libdtt.a drivers/libdrivers.a drivers/nand/libnand.a drivers/nand_legacy/libnand_legacy.a drivers/sk98lin/libsk98lin.a post/libpost.a post/cpu/libcpu.a common/libcommon.a net/uip-1.0/uip/libuip.a --end-group -L /tmp/demo/compiler/usr/crosstool/gcc-3.4.5-glibc-2.3.6/arm-linux/bin/../lib/gcc/arm-linux/3.4.5 -lgcc \
                        -Map u-boot.map -o u-boot
arm-linux-objcopy --gap-fill=0xff -O srec u-boot u-boot.srec
arm-linux-objcopy --gap-fill=0xff -O binary u-boot u-boot.bin
[srini@localhost sbc9261-uboot-uip-ipv6]# ls
arm_config.mk       config.mk  doc       i386_config.mk  lib_generic     lib_nios        MAKEALL               nand_spl         ppc_config.mk   System.map  u-boot.srec
blackfin_config.mk  COPYING    drivers   include         lib_i386        lib_nios2       Makefile              net              README          tools
board               cpu        dtt       kermit_connect  lib_m68k        lib_ppc         microblaze_config.mk  nios2_config.mk  README.ronetix  u-boot
CHANGELOG           CREDITS    examples  lib_arm         lib_microblaze  m68k_config.mk  mips_config.mk        nios_config.mk   rtc             u-boot.bin
common              disk       fs        lib_blackfin    lib_mips        MAINTAINERS     mkconfig              post             rules.mk        u-boot.map
[srini@localhost sbc9261-uboot-uip-ipv6]#
```
### Video tutorial and demo ###

http://www.youtube.com/watch?v=bk7lcbredWg