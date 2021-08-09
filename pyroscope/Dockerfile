FROM ubuntu:latest

ENV DEBIAN_FRONTEND=non-interactive

RUN apt-get -y update
RUN apt-get -y install gcc make vim php php-dev wget
COPY . /app
WORKDIR /app
