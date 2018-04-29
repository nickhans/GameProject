#! /bin/bash

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

# tests all of the movement functions
run ./game <<EOF
test_bot
go 1
go cw
go cw
go cw
go cw
go cw
go cw
go ccw
go ccw
go ccw
go ccw
go ccw
go ccw
go center
go 1
go center
go 2
go center
go 3
go center
go 4
go center
go 5
go center
go 6
go center
quit
EOF

run ./game <<EOF
test_bot
examine room
examine trapdoor
go 1
examine book
take book
examine book
inventory
drop
drop book
drop desk
take
take room
take desk
take book
go center
put trapdoor
examine room
examine trapdoor
examine book
remove book
room
remove book
trapdoor
examine trapdoor
examine book
inventory
examine room
drop
examine room
quit
EOF

run ./game <<EOF
test_bot
help
help examine
help go
help take
help drop
help inventory
help put
help remove
help asdas
quit
EOF




