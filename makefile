all: foo.c
	gcc foo.c

run: a.out
	./a.out
	convert foo.ppm foo.jpeg

clean:
	touch foo~ foo.ppm foo.png foo.jpeg foo.out
	rm *~ *.ppm *.png *.jpeg *.out
	clear
