CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
SOURCES = $(wildcard *.cc)
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a4q3
${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
-include ${DEPENDS}