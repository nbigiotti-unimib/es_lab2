CPPC=c++
BIN_DIR=bin
CPPFLAGS=-lLAB2	`root-config --glibs --cflags`
es91:	src/es_91/main_91.cpp
	$(CPPC)	$^	-o	$(BIN_DIR)/$@	$(CPPFLAGS)

run91:	es91
	$(BIN_DIR)/$^

es92:	src/es_92/main_92.cpp
	$(CPPC)	$^	-o	$(BIN_DIR)/$@	$(CPPFLAGS)

run92:	es92
	$(BIN_DIR)/$^	2	1000000

es93:	src/es_93/main_93.cpp
	$(CPPC)	$^	-o	$(BIN_DIR)/$@	$(CPPFLAGS)

run93:	es93
	$(BIN_DIR)/$^

es94:	src/es_94/main_94.cpp
	$(CPPC)	$^	-o	$(BIN_DIR)/$@	$(CPPFLAGS)

run94:	es94
	$(BIN_DIR)/$^

es95:	src/es_95/main_95.cpp
	$(CPPC)	$^	-o	$(BIN_DIR)/$@	$(CPPFLAGS)

run95:	es95
	$(BIN_DIR)/$^

