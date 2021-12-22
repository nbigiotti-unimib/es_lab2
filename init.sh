#!bin/bash
N_LESS=""
LESS_DIR=""
N_EX=""

CPP_FILE_TEMPL="#include <iostream>\n\nint main(int argc , char * argv[]) {\n\tprintf(\"TEST: OK\");\n\treturn 0;\n}"

read -p "Inserire il numero della lezione: " N_LESS
read -p "Inserire numero di esercizi: " N_EX

LESS_DIR="lez$N_LESS"

mkdir -p $LESS_DIR/{src,include,bin,misc_output,res}

touch $LESS_DIR/Makefile

echo 'CPPC=c++' >> $LESS_DIR/Makefile
echo 'BIN_DIR=bin' >> $LESS_DIR/Makefile
echo 'CPPFLAGS=`root-config --glibs --cflags`   -lLAB2' >> $LESS_DIR/Makefile

for i in `seq 1 $N_EX`;
do
    mkdir -p $LESS_DIR/src/es_$N_LESS$i
    touch $LESS_DIR/src/es_$N_LESS$i/main_$N_LESS$i.cpp
    
    printf "$CPP_FILE_TEMPL" > $LESS_DIR/src/es_$N_LESS$i/main_$N_LESS$i.cpp
       
    printf "es$N_LESS$i:\tsrc/es_$N_LESS$i/main_$N_LESS$i.cpp\n" >> $LESS_DIR/Makefile
    printf "\t\$(CPPC)\t\$^\t-o\t\$(BIN_DIR)/\$@\t\$(CPPFLAGS)\n\n" >> $LESS_DIR/Makefile
    printf "run$N_LESS$i:\tes$N_LESS$i\n" >> $LESS_DIR/Makefile
    printf "\t\$(BIN_DIR)/$^\n\n" >> $LESS_DIR/Makefile
done


#git add .
#git commit -m "Initialized directories and files for lesson $N_LESS"
#git push