#! /bin/bash

compile() {
    clear
    echo "Preparing Compile"
    rm game   
    echo ""          #removes current game.exec
    echo "Compiling game" 
    echo ""  
    make                #runs makefile to compile individual .c files    
    #add .o files below
    gcc main.o location.o object.o player.o container.o misc.o score.o -o game      
    if [ -e game ]      #checks if game.exec was made
        then {
            echo ""
            echo "Compile Successful"
            echo ""
        } else {
            echo "Compile Failure"
            exit -1     #if file was not made compilation fails
        }
    fi
    # clear
    ./game
    exit 0;
}

compile

