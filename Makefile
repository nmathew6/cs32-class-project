#CXX=clang++
CXX=g++

CXXFLAGS= -g -O3 -std=c++14 

BINARIES=dataProj testPSState testPSSort testBelowPSort testAgDemog testAgPS

all: ${BINARIES}

tests: ${BINARIES}
	./testPSState
	./testPSSort
	./testBelowPSort
	./testAgDemog
	./testAgPS


dataProj: dataAQ.o demogCombo.o demogData.o raceDemogData.o psData.o psCombo.o parse.o main.o
	${CXX} $^ -o $@

testPSState: testPSState.o dataAQ.o demogCombo.o demogData.o raceDemogData.o psData.o psCombo.o  parse.o  tddFuncs.o
	${CXX} $^ -o $@

testPSSort: testPSSort.o dataAQ.o demogCombo.o demogData.o raceDemogData.o psData.o psCombo.o  parse.o tddFuncs.o
	${CXX} $^ -o $@

testBelowPSort: testBelowPSort.o dataAQ.o demogCombo.o demogData.o raceDemogData.o psData.o psCombo.o  parse.o tddFuncs.o
	${CXX} $^ -o $@

testAgDemog: testAgDemog.o dataAQ.o demogCombo.o demogData.o raceDemogData.o psData.o psCombo.o  parse.o tddFuncs.o
	${CXX} $^ -o $@

testAgPS: testAgPS.o dataAQ.o demogCombo.o demogData.o raceDemogData.o psData.o psCombo.o  parse.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o 