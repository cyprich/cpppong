build: src/main.cpp
	@echo "Compiling..."
	@g++ src/main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o build/main
run: build
	@echo "Running..."
	@echo " "
	@./build/main
clear:
	@rm -r build
	@echo "All clear!"
