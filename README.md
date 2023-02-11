## MPI
## Instalacion Mapi Ubunto
-----
sudo apt-get update
sudo apt-get install libopenmpi-dev
-----
verificar
-----
mpiexec --version
-------
compilar
--- mpicxx main.cpp -o ejemplo1progra
----
Ejecutar
-----
mpiexec -n 4 ./ejemplo01