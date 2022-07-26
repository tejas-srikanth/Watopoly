CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD
SOURCES = $(wildcard *.cc)
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}
EXEC = watopoly
${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}
-include ${DEPENDS}
