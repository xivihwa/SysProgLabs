savedcmd_/home/antonenko/SysProg/lab4/list_module.mod := printf '%s\n'   list_module.o | awk '!x[$$0]++ { print("/home/antonenko/SysProg/lab4/"$$0) }' > /home/antonenko/SysProg/lab4/list_module.mod
