all: compile

compile:
		g++ main.cpp LATEX//LatexFunctions.cpp GetLabAtr//GetLabAttribute.cpp -o app
run: app
		./app