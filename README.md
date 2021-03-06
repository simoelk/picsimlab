
# PICSimLab - PIC Simulator Laboratory

PICSimLab is a realtime emulator of development boards with integrated MPLABX/avr-gdb debugger. 
PICSimLab supports some picsim microcontrollers and some simavr microcontrollers.
PICSimLab have integration with  MPLABX/Arduino IDE for programming the boards microcontrollers.

![PICsimLab](docs/screenshot.png?raw=true "PICsimLab")

![PICsimLab](docs/picsimlab4.png?raw=true "PICsimLab")

## Requirements for compiling:

wxwidget 	- For graphic suport		   http://www.wxwidgets.org

picsim          - PIC simulator                    https://github.com/lcgamboa/picsim 

lxrad           - Graphic library                  https://github.com/lcgamboa/lxrad 

simavr          - AVR simulator                    https://github.com/buserror/simavr

## Utils:

picsimlab_md    - for debug with MPLABX      https://github.com/lcgamboa/picsimlab_md

com0com		- For serial emulation in windows  http://com0com.sourceforge.net/ 

tty0tty 	- For serial emulation in linux    https://github.com/lcgamboa/tty0tty 

## Stable version executables download 

https://github.com/lcgamboa/picsimlab/releases

If you are on macOS you can run picsimlab using Wine:

- Download and install [`xquartz`](https://www.xquartz.org)
- Download and install [Wine](https://dl.winehq.org/wine-builds/macosx/download.html)
- Download the executable and double-click it to run the installer

## Install from source

In Debian Linux and derivatives:

```
git clone https://github.com/lcgamboa/picsimlab.git
cd picsimlab
./picsimlab_build_all_and_deps.sh
```
## Cross-compiling for windows 64bits (from linux or wsl on win10)

In Debian Linux and derivatives:

```
git clone https://github.com/lcgamboa/picsimlab.git
cd picsimlab
./picsimlab_build_w64.sh
```
## Troubleshooting:
The simulation in PICSimLab consists of 3 parts:

- The microcontroller program
- Microcontroller simulation (made by [picsim](https://github.com/lcgamboa/picsim) and [simavr](https://github.com/buserror/simavr))
- Simulation of boards and parts

When a problem occurs it is important to detect where it is occurring.

One of the most common problems is the error in the microcontroller program. Before creating an issue, test your code on a real circuit (even partially) to make sure the problem is not there.

Errors in the microcontroller simulation can be detected using code debugging. Any instruction execution or peripheral behavior outside the expected should be reported in the project of simulator used ([picsim](https://github.com/lcgamboa/picsim) or [simavr](https://github.com/buserror/simavr)).

If the problem is not in either of the previous two options, the problem is probably in PICSimLab. A good practice is to send a source code together with a PICSimLab workspace (.pzw file) to open the issue about the problem.


## Info

[Online Documentation](https://lcgamboa.github.io/picsimlab/)

[Development Documentation](https://lcgamboa.github.io/picsimlab/devel/html/)

[Examples](https://lcgamboa.github.io/picsimlab_examples/examples/examples_index.html)

[Changelog](./CHANGELOG.md)

[TODO list](./TODO.md)

[Online version of PICSimLab](https://lcgamboa.github.io/)

