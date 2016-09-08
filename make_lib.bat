cd libPrj


del *.o /Q /F
gcc -c binTreeSim.c -o binTreeSim.o
gcc -c PDOIL_ext.c -o PDOIL_ext.o
ar rcs ..\libTreeSim.a o\* binTreeSim.o PDOIL_ext.o
del *.o /Q /F

cd ..
