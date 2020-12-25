FROM ubuntu:18.04
MAINTAINER Petr Kurapov <petr.kurapov@gmail.com>

ARG REPO=kurapov-peter/np-complete

RUN apt-get -y update && apt-get install -y wget build-essential vim gcc g++ git python3 cmake && rm -rf /var/lib/apt/lists/*

WORKDIR /usr/local/src

RUN git clone --recursive https://github.com/$REPO.git repo
RUN cd repo && git checkout master

ENV NP_HOME=/usr/local/src/repo
RUN mkdir build && cd build

WORKDIR $NP_HOME/build
RUN cmake ..
RUN make -j`nproc`

WORKDIR ../
