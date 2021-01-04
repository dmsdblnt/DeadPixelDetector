FROM archlinux

WORKDIR /usr/src

COPY / .

RUN cat CMakeLists.txt
RUN pacman -Sy gcc cmake opencv make python3 --noconfirm
RUN cmake CMakeLists.txt
RUN make -j1

EXPOSE 8080

CMD [ "./main" ]