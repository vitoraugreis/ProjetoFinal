CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = ProjetoFinal

BUILD_DIR = ./build
INCLUDE_DIR = ./include
SRC_DIR = ./src

${TARGET} : ${BUILD_DIR}/main.o ${BUILD_DIR}/ControleClientes.o ${BUILD_DIR}/ControleMidia.o ${BUILD_DIR}/Fita.o ${BUILD_DIR}/Dvd.o ${BUILD_DIR}/Midia.o ${BUILD_DIR}/Cliente.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${TARGET}

${BUILD_DIR}/ControleMidia.o : ${INCLUDE_DIR}/ControleMidia/ControleMidia.hpp ${SRC_DIR}/ControleMidia/ControleMidia.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleMidia/ControleMidia.cpp -o ${BUILD_DIR}/ControleMidia.o

${BUILD_DIR}/ControleClientes.o : ${INCLUDE_DIR}/ControleClientes/ControleClientes.hpp ${SRC_DIR}/ControleClientes/ControleClientes.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleClientes -c ${SRC_DIR}/ControleClientes/ControleClientes.cpp -o ${BUILD_DIR}/ControleClientes.o

${BUILD_DIR}/Fita.o : ${INCLUDE_DIR}/ControleMidia/Fita.hpp ${SRC_DIR}/ControleMidia/Fita.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleMidia/Fita.cpp -o ${BUILD_DIR}/Fita.o

${BUILD_DIR}/Dvd.o : ${INCLUDE_DIR}/ControleMidia/Dvd.hpp ${SRC_DIR}/ControleMidia/Dvd.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleMidia/Dvd.cpp -o ${BUILD_DIR}/Dvd.o

${BUILD_DIR}/Midia.o : ${INCLUDE_DIR}/ControleMidia/Midia.hpp ${SRC_DIR}/ControleMidia/Midia.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleMidia/Midia.cpp -o ${BUILD_DIR}/Midia.o

${BUILD_DIR}/Cliente.o : ${INCLUDE_DIR}/ControleClientes/Cliente.hpp ${SRC_DIR}/ControleClientes/Cliente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleClientes/ -c ${SRC_DIR}/ControleClientes/Cliente.cpp -o ${BUILD_DIR}/Cliente.o

${BUILD_DIR}/main.o : ${INCLUDE_DIR}/ControleClientes/ControleClientes.hpp ${INCLUDE_DIR}/ControleMidia/ControleMidia.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleClientes/ -I ${INCLUDE_DIR}/ControleMidia/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o