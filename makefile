CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = ProjetoFinal

BUILD_DIR = ./build
INCLUDE_DIR = ./include
SRC_DIR = ./src
TST_DIR = ./tests
DOC_DIR = ./doctest

${TARGET} : ${BUILD_DIR}/main.o ${BUILD_DIR}/ControleLocacao.o ${BUILD_DIR}/ControleClientes.o ${BUILD_DIR}/ControleMidia.o ${BUILD_DIR}/Fita.o ${BUILD_DIR}/Dvd.o ${BUILD_DIR}/Midia.o ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/ControleClientesExceptions.o ${BUILD_DIR}/ControleMidiaExceptions.o ${BUILD_DIR}/test_controlemidia.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${TARGET}
 
${BUILD_DIR}/ControleClientesExceptions.o : ${INCLUDE_DIR}/ControleClientes/ControleClientesExceptions.hpp ${SRC_DIR}/ControleClientes/ControleClientesExceptions.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleClientes -c ${SRC_DIR}/ControleClientes/ControleClientesExceptions.cpp -o ${BUILD_DIR}/ControleClientesExceptions.o

${BUILD_DIR}/ControleMidiaExceptions.o : ${INCLUDE_DIR}/ControleMidia/ControleMidiaExceptions.hpp ${SRC_DIR}/ControleMidia/ControleMidiaExceptions.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleMidia/ControleMidiaExceptions.cpp -o ${BUILD_DIR}/ControleMidiaExceptions.o

${BUILD_DIR}/ControleLocacao.o : ${INCLUDE_DIR}/ControleLocacao/ControleLocacao.hpp ${INCLUDE_DIR}/ControleClientes/ControleClientes.hpp ${INCLUDE_DIR}/ControleMidia/ControleMidia.hpp ${SRC_DIR}/ControleLocacao/ControleLocacao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleLocacao -I ${INCLUDE_DIR}/ControleClientes -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleLocacao/ControleLocacao.cpp -o ${BUILD_DIR}/ControleLocacao.o

${BUILD_DIR}/ControleMidia.o : ${INCLUDE_DIR}/ControleMidia/ControleMidia.hpp ${SRC_DIR}/ControleMidia/ControleMidia.cpp ${BUILD_DIR}/ControleMidiaExceptions.o
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleMidia/ControleMidia.cpp -o ${BUILD_DIR}/ControleMidia.o

${BUILD_DIR}/ControleClientes.o : ${INCLUDE_DIR}/ControleClientes/ControleClientes.hpp ${SRC_DIR}/ControleClientes/ControleClientes.cpp ${BUILD_DIR}/ControleClientesExceptions.o 
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleClientes -c ${SRC_DIR}/ControleClientes/ControleClientes.cpp -o ${BUILD_DIR}/ControleClientes.o

${BUILD_DIR}/Fita.o : ${INCLUDE_DIR}/ControleMidia/Fita.hpp ${SRC_DIR}/ControleMidia/Fita.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleMidia/Fita.cpp -o ${BUILD_DIR}/Fita.o

${BUILD_DIR}/Dvd.o : ${INCLUDE_DIR}/ControleMidia/Dvd.hpp ${SRC_DIR}/ControleMidia/Dvd.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleMidia/Dvd.cpp -o ${BUILD_DIR}/Dvd.o

${BUILD_DIR}/Midia.o : ${INCLUDE_DIR}/ControleMidia/Midia.hpp ${SRC_DIR}/ControleMidia/Midia.cpp ${BUILD_DIR}/ControleMidiaExceptions.o
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia -c ${SRC_DIR}/ControleMidia/Midia.cpp -o ${BUILD_DIR}/Midia.o

${BUILD_DIR}/Cliente.o : ${INCLUDE_DIR}/ControleClientes/Cliente.hpp ${SRC_DIR}/ControleClientes/Cliente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleClientes/ -c ${SRC_DIR}/ControleClientes/Cliente.cpp -o ${BUILD_DIR}/Cliente.o

${BUILD_DIR}/main.o : ${INCLUDE_DIR}/ControleClientes/ControleClientes.hpp ${INCLUDE_DIR}/ControleMidia/ControleMidia.hpp ${INCLUDE_DIR}/ControleLocacao/ControleLocacao.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleClientes/ -I ${INCLUDE_DIR}/ControleMidia/ -I ${INCLUDE_DIR}/ControleLocacao/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

#${BUILD_DIR}/test_controlemidia.o : ${INCLUDE_DIR}/ControleMidia/ControleMidiaExceptions.hpp ${INCLUDE_DIR}/ControleMidia/ControleMidia.hpp ${INCLUDE_DIR}/ControleLocacao/ControleLocacao.hpp ${TST_DIR}/ControleMidia/test_controlemidia.cpp
#	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleMidia/ -I ${INCLUDE_DIR}/ControleLocacao/ -I -c ${TST_DIR}/ControleMidia/test_controlemidia.cpp -o ${BUILD_DIR}/test_controlemidia.o
