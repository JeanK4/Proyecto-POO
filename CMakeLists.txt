cmake_minimum_required(VERSION 3.26)
project(Proyecto_POO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proyecto_POO
        aeronave.cpp
        aeropuerto.cpp
        main.cpp
        pasajero.cpp
        persona.cpp
        PuertaEmbarque.cpp
        PuertaEmbarque.h
        TorreControl.cpp
        tripulante.cpp
        usuario.cpp
        vuelo.cpp)
