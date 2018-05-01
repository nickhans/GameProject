#! /bin/bash

compile() {
    DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
    echo "$DIR"
    clear
    echo "Preparing Compile"
    rm game   
    echo ""          #removes current game.exec
    echo "Compiling game" 
    echo ""
    cd $DIR  
    make                #runs makefile to compile individual .c files    
    #add .o files below
    gcc main.o location.o object.o player.o container.o misc.o score.o event.o -o game      
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
    clear
    ./game
    read -p "Press [Enter] to end..."
    exit 0;
}

compile

