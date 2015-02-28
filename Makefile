all: display

a.out: drawing.o main.o mesh.o camera.o matrix.o
	g++ $^ -o $@



main.o: main.cpp drawing.h mesh.h
	g++ main.cpp -c
	
drawing.o: drawing.cpp drawing.h
	g++ drawing.cpp -c

mesh.o: mesh.cpp mesh.h matrix.h
	g++ mesh.cpp -c

camera.o: camera.cpp camera.h mesh.h drawing.h matrix.h
	g++ camera.cpp -c

matrix.o: matrix.cpp matrix.h
	g++ matrix.cpp -c



run: out.ppm

out.ppm: a.out
	./a.out

display: out.ppm
	display out.ppm

time: a.out
	time -v ./a.out

clean:
	rm a.out *.o out.ppm
