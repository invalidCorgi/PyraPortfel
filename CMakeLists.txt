cmake_minimum_required(VERSION 3.9)
project(PyraPortfel)

set(CMAKE_CXX_STANDARD 17)

add_executable(PyraPortfel main.cpp PortfelInwestycyjny.cpp Aktywa.cpp Aktywa.h Lokata.cpp Lokata.h Nieruchomosc.cpp Nieruchomosc.h Kontrakt.cpp Kontrakt.h ProduktStrukturyzowany.cpp ProduktStrukturyzowany.h IKE.cpp IKE.h main.h)