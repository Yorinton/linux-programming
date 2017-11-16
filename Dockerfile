FROM ubuntu:latest
RUN mkdir /workspace
ADD . /workspace
WORKDIR /workspace
