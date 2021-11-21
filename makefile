name = ${}

run:
	g++ main.cpp -lGL -lglut -o bin/triangle
	./bin/triangle

snow:
	g++ snowman.cpp -lglut -lGL -lGLU -lm -o bin/snowman
	./bin/snowman

clean:
	rm -rf *.out
