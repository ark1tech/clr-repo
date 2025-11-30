<details>
<summary><b>env setup</b></summary>

#### image
- download `CS 140.ova` image from UVLe
- on VB, go to File > Import Appliance, select `CS 140.ova`, and click Next until finished.
#### virtualbox
- optimize hardware for kernel compiling, 
  - right-click the `CS 140` machine in VirtualBox -> Settings.
  - go to System > Processor
  - increase allocated cores
#### shared folders
- create a folder on the computer `~/Desktop/140workflow`
- on VB's setting for VM, go to shared folders
  - folder path: `~/Desktop/140_workflow`
  - folder name: `140_shared`
  - auto-mount: checked
  - make Machine-permanent: checked
  - read-only: unchecked
  - make global: unchecked

</details>

<hr>

<details>
<summary><b>linux kernel</b></summary>

#### syncing
- download source code (in this repo btw frfr)
- move the kernel source code in the shared folder `~/Desktop/140_workflow`
- make a guest directory for compilation `mkdir -p ~/Desktop/linux-src`
  - make sure to ***not compile*** inside the shared folder
- in the guest terminal 
  ```
  rsync -av --times --omit-dir-times --no-perms --no-owner --no-group --update /media/140_shared/linux-6.17.8/ ~/Desktop/linux-src/
  ```
  to copy files to the compile directory. replace `/media/140_shared/linux-6.17.8/` with the mount point with a relative path to the source code.  *run this command for each change in the source code*.

#### compiling
- `cd` to the source code in guest 
- generate config by running `make defconfig`
- to compile the Linux kernel using all available CPU cores, run `` make -j/`nproc` ``
- verify if compiled correctly when these files are present
  - `vmlinux`
  - `vmlinux.map`
  - `System.map`

#### installing
- run `sudo make install`
- once Ubuntu has loaded, open a terminal instance and run `uname -mrs` 
  - should display `Linux 6.17.8 x86_64` as its output.

#### recompiling and rebooting
- run `sudo make install`
- reboot
- confirm `uname -mrs` 

</details>

<details>
<summary><b>LKMs</b></summary>

#### installing
- run `sudo insmod pcbcopylog.ko`
- verify by `dmesg | tail -n 20`
- run `sudo rmmod pcbcopylog.ko` to unload 

</details>