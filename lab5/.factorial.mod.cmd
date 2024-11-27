savedcmd_/home/antonenko/SysProg/lab5/factorial.mod := printf '%s\n'   factorial.o | awk '!x[$$0]++ { print("/home/antonenko/SysProg/lab5/"$$0) }' > /home/antonenko/SysProg/lab5/factorial.mod
