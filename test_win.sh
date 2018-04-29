#! /bin/bash/

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

# running this will do all the commands necessary to win the game
run ./game <<EOF
test_bot
go 1
take book
go ccw
go ccw
go ccw
put bookshelf
take circle
go center
put trapdoor
go 6
remove star
tree
go center
put trapdoor
go 4
remove battery
desk
go ccw
put robot
take square
go center
put trapdoor
go 6
take chair
go cw
go cw
go cw
put desk
take triangle
go center
put trapdoor
EOF