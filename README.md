# AlarmaPI
Alarm for Raspberry PI

### Hardware Requeriments
* Raspberry PI 
* Wifi Dongle
* Motorola C115 (optional)
* Jack for Motorola C115 handset and Arduino Female Wires 
* I2C Display 24 x 4

### Dependencies

* Boost.Asio or standalone Asio
* Boost is required to compile the examples
* For HTTPS: OpenSSL libraries 
* libpcap
* openssl
### Dependencies Instalation
*Centos
```sh
yum install libpcap-devel
```
*Fedora
```sh
dnf install libpcap-devel
```

*Debian
```sh

```

```sh
git clone https://github.com/mfontanini/libtins.git
```

### Compile and run
Compile with
```sh
make
./Alarma
```
