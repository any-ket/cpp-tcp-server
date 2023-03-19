# c-tcp-server

TCP Server for chat service written in cpp

## Requirements

You'll need gcc to build the server.

## Installation

will update MakeFile and provide support for `make` command. Right now you can use:

```
g++ src/main.cpp src/client.cpp -o server && ./server

```

to build and run server

## Usage

You can use netcat to connect to server
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
