
# c-tcp-server

TCP Server for chat service written in cpp
## Requirements

You'll need g++ compiler to build the server.

## Installation
`make`

## Usage

use `make run` to start the server

You can use netcat to connect to the server

```
nc 127.0.0.1 8080
```

## Directory structure
```
|-- Makefile           <- Project makefile
|-- README             <- Project README
|-- bin                <- Compiled binaries
|   `-- run            <- Project main executable
|-- build              <- Static objects and intermediate files
|-- data               <- Project data
|   |-- raw            <- Raw data
|   |-- interim        <- Interm data
|   |-- input          <- Input data
|   |-- output         <- Output data
|-- docs               <- Documentation
|-- include            <- Header files
|-- lib                <- Dynamic objects
|-- src                <- Source files
`-- tests              <- Unit tests
```
