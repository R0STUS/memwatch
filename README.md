# memwatch

A utility to monitor memory usage of processes in POSIX-compliant systems. Designed for Unix-like systems that provide a `/proc` filesystem.

## Installation

```bash
make
sudo make install
sudo make install-man
```

## Uninstallation

```bash
sudo make uninstall
sudo make uninstall-man
```

## Clean build files

```bash
make clean
```

## Usage

After installation, run:

```bash
memwatch
```

For detailed information, use the manual:

```bash
man memwatch
```
