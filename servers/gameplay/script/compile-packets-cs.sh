#!/usr/bin/env bash

protoc --proto_path=../packets/protobufs/ --csharp_out=\
../../../../Ex-Chick-It-Server-DotMQ-Test/Ex-Chick-It-Server-DotMQ-Test/Packets action.proto