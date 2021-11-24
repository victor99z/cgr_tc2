name = ${}

run: robot snow construction

robot:
	g++ robot.cpp -lglut -lGL -lGLU -lm -o bin/robot
	./bin/robot

snow:
	g++ snowman.cpp -lglut -lGL -lGLU -lm -o bin/snowman
	./bin/snowman

construction:
	g++ construction.cpp -lglut -lGL -lGLU -lm -o bin/construction
	./bin/construction

clean:
	rm -rf *.out
