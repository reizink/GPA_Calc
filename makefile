a.out: collegemain.o course.o college.o
	g++ collegemain.o course.o college.o
course.o: course.cc course.h
	g++ -c course.cc
college.o: college.cc college.h
	g++ -c college.cc
collegemain.o: collegemain.cc
	g++ -c collegemain.cc

