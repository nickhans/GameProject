#! /bin/bash

compile() {
    clear
    echo "Preparing Compile"
    rm game                                      #removes current game.exec
    echo "Compiling game"   
    make        #runs makefile to compile individual .c files    
    #add .o files below
    gcc main.o location.o object.o misc.o -o game      
    if [ -e game ]                               #checks if game.exec was made
        then {
            echo "Compile Successful"
            echo ""
        } else {
            echo "Compile Failure"
            exit -1                              #if file was not made compilation fails
        }
    fi
    # clear
    ./game
    exit 0;
}

compile

