# Kernel-TaskStruct-Reader

This implements a simple kernel module to take the `pid` of a process as a parameter and obtain the `task_struct` of the `pid`.

## Installation

Clone this repo, `cd` into it, and run:

```console
make
```

This will generate the `taskStructReader.ko` file.

## Usage

You can run the module using:
```console
sudo insmod taskStructReader.ko pidint=<insert pid here>
```

You can check the output using:
```console
sudo dmesg -t | tail -4
```

You can remove the module using:

```console
sudo rmmod taskStructReader
```

## References

[The Linux Kernel Module Programming](https://sysprog21.github.io/lkmpg/)