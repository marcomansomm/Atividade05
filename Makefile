bin: calculoMatriz.c
	gcc $< -o $@ -pthread

.PHONY: run clean

run:
	./bin

clean:
	rm bin