# Bash Setns
Take bash on tour with builtin setns.

```
$ make
$ sudo -s
# enable -f ./setns.so setns
# cat /etc/lsb-release 
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=20.04
DISTRIB_CODENAME=focal
DISTRIB_DESCRIPTION="Ubuntu 20.04.2 LTS"
# setns /proc/<alpine-container-pid>/ns/mnt 
# cat /etc/alpine-release 
3.13.1
```
