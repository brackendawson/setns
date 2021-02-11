# Bash Setns
Take bash on tour with builtin setns.

### Build it
You need the bash-builtin headers.
```
$ make
```

### Install it
Load it into bash either once or in your .bashrc:
```
$ enable -f ./setns.so setns
```

### Use it.
For example, you can take your Ubuntu's bash into an Alpine container's filesystem (as root):
```
# cat /etc/lsb-release 
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=20.04
DISTRIB_CODENAME=focal
DISTRIB_DESCRIPTION="Ubuntu 20.04.2 LTS"

# setns /proc/<alpine-container-pid>/ns/mnt 

# cat /etc/alpine-release 
3.13.1
```
