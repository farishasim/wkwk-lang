CXX = g++
DRIVER = driver
BIN = bin
VM = ./vm

compile: compile_vm

compile_vm:
	cd ${VM}; \
	${CXX} -c *.cpp; \
	${CXX} -o ${DRIVER} *.o; \
	rm *.o; \