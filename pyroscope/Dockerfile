FROM ubuntu:latest

ENV DEBIAN_FRONTEND=non-interactive

RUN apt-get -y update
RUN apt-get -y install gcc make vim wget git autoconf bison \
		re2c php-dev pkg-config libxml2-dev libsqlite3-dev 

RUN git clone https://github.com/php/php-src.git
WORKDIR /php-src/

# This file is available only in php8, and works only in php-8.1.0alpha1 release
RUN git checkout php-8.1.0alpha1
RUN cp build/gen_stub.php /tmp/gen_stub.php

# We want to stay with php7 for building & deployment
RUN git checkout php-7.4.3
RUN ./buildconf --force
RUN ./configure --prefix=/php-bin/
RUN make -j
RUN make install

ARG pyroscope_libs_sha
ARG pyroscope_php_tag="v0.0.0"

WORKDIR /app/
RUN wget -qnc \
https://dl.pyroscope.io/static-libs/$pyroscope_libs_sha/linux-amd64/libpyroscope.phpspy.a -O libpyroscope.phpspy.a
RUN wget -qnc \
https://dl.pyroscope.io/static-libs/$pyroscope_libs_sha/linux-amd64/libpyroscope.phpspy.h -O libpyroscope.phpspy.h
RUN wget -qnc \
https://dl.pyroscope.io/static-libs/$pyroscope_libs_sha/linux-amd64/libphpspy.a -O libphpspy.a

# TODO: Tests were removed, but there is an example in the skeleton which can be used
COPY config.m4 config.w32 pyroscope.c php_pyroscope.h pyroscope.stub.php /app

ENV PATH="/php-bin/bin:${PATH}"
RUN /tmp/gen_stub.php
RUN phpize
RUN LDFLAGS="-pthread -lrt -lm -ldl -Wl,--whole-archive libpyroscope.phpspy.a libphpspy.a -Wl,--no-whole-archive" ./configure
RUN make -j
RUN make install



