FROM ubuntu:latest
ENV DEBIAN_FRONTEND=non-interactive

RUN apt-get -y update
RUN apt-get -y install gcc make vim php php-ffi wget

ARG pyroscope_libs_sha

WORKDIR app/
RUN wget -qnc https://dl.pyroscope.io/static-libs/$pyroscope_libs_sha/linux-amd64/libpyroscope.phpspy.a -O libpyroscope.phpspy.a
RUN wget -qnc https://dl.pyroscope.io/static-libs/$pyroscope_libs_sha/linux-amd64/libpyroscope.phpspy.h -O libpyroscope.phpspy.h
RUN wget -qnc https://dl.pyroscope.io/static-libs/$pyroscope_libs_sha/linux-amd64/libphpspy.a -O libphpspy.a
COPY src/Hello.php composer.json ./app/

RUN gcc -shared -Wl,--whole-archive libpyroscope.phpspy.a libphpspy.a -Wl,--no-whole-archive -o libpyroscope.phpspy.so

