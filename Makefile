CXX = g++
DRIVER = driver
BIN = bin
VM = ./vm
INTERPRETER = boi

compile: compile_boi

driver:
	cd ${VM}; \
	${CXX} -c *.cpp; \
	${CXX} -o ${DRIVER} *.o; \
	rm *.o; \

compile_boi: vm/VM.o boi.o
	mv vm/VM.o .; \
	${CXX} -o ${INTERPRETER} *.o; \
	rm *.o \