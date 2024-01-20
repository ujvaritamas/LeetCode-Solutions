FROM ubuntu:latest as cpp_test

RUN apt-get -y update && apt-get install -y
RUN apt-get -y install g++ cmake git

WORKDIR /usr/src/app
COPY . .

# Run cmake configure & build process
#RUN mkdir ./build
#RUN cmake -B/build -S . -D CMAKE_BUILD_TYPE=Release
#RUN cmake --build /build

CMD ["bash", "-c", "while true; do sleep 3600; done"]



FROM golang:latest as go_test

WORKDIR /usr/src/app
COPY . .

CMD ["bash", "-c", "while true; do sleep 3600; done"]