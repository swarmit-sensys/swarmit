 # SwarmIT

SwarmIT provides a embedded C port for nRF53 as well as Python based services to
easily build and deploy a robotic swarm infrastructure testbed.
ARM TrustZone is used to create a sandboxed user environment on each device
under test, without requiring a control co-processor attached to it.

## Features

- Experiment management: start, stop, monitor and status check
- Deploy a custom firmware on all or on a subset of robots of a swarm testbed
- Resilient robot state: even when crashed by buggy user code, the robot can be reprogrammed remotely and wirelessly

## Usage

### Get the code

Swarmit depends on the [DotBot-firmware](https://github.com/swarmit-sensys/DotBot-firmware)
and [Mari](https://github.com/swarmit-sensys/mari) repositories. They are included
in the codebase as [Git submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules).

Use the following command to clone the Swarmit codebase locally:

```
git clone --recurse-submodules https://github.com/swarmit-sensys/swarmit.git
```

### Embedded C code

SwarmIT embedded C code can be built using
[Segger Embedded Studio (SES)](https://www.segger.com/products/development-tools/embedded-studio/).
Use Tools > Package manager to install the CMSIS 5 CMSIS-CORE, CMSIS-DSP and nRF packages.

To provision a device, follow the following steps:
1. open [netcore.emProject](swarmit-netcore.emProject)
   and [bootloader.emProject](swarmit-bootloader-dotbot-v3.emProject)
   (or [bootloader.emProject](swarmit-bootloader-dotbot-v2.emProject) depending on
   your robot version) in SES
2. build and load the netcore application on the nRF53 network core,
3. build and load the bootloader application on the nRF53 application core.

The device is now ready.

### Gateway

The communication between the computer and the swarm devices is performed via a
gateway board connected via USB to the computer.

This gateway uses the [mari](https://github.com/swarmit-sensys/mari) network stack and
must run the Mari gateway firmware.

The documentation to setup a Mari gateway is located
[here](https://github.com/swarmit-sensys/mari/wiki/Getting-started#running-mari-network-on-your-computer).

### Python CLI script

The Python CLI script provides commands for flashing, starting and stopping user
code on the device, as well as monitoring and checking the status of devices
in the swarm.

The Python CLI script connects via a virtual COM port to the gateway connected to
the computer.

The Python CLI script is available on PyPI. Install it using:

```
pip install swarmit
```

Print usage using `swarmit --help`:

```
Usage: swarmit [OPTIONS] COMMAND [ARGS]...

Options:
  -p, --port TEXT                 Serial port to use to send the bitstream to
                                  the gateway. Default: /dev/ttyACM0.
  -b, --baudrate INTEGER          Serial port baudrate. Default: 1000000.
  -H, --mqtt-host TEXT            MQTT host. Default: localhost.
  -P, --mqtt-port INTEGER         MQTT port. Default: 1883.
  -T, --mqtt-use_tls              Use TLS with MQTT.
  -n, --network-id INTEGER        Marilib network ID to use. Default: 1
  -a, --adapter [edge|cloud]
                                  Choose the adapter to communicate with the
                                  gateway.  [default: edge]
  -d, --devices TEXT              Subset list of devices to interact with,
                                  separated with ,
  -v, --verbose                   Enable verbose mode.
  -V, --version                   Show the version and exit.
  -h, --help                      Show this message and exit.

Commands:
  flash    Flash a firmware to the robots.
  message  Send a custom text message to the robots.
  monitor  Monitor running applications.
  reset    Reset robots locations.
  start    Start the user application.
  status   Print current status of the robots.
  stop     Stop the user application.
```
