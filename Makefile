all:
	g++ -o avl-tree *.cpp -O3

clean:
	rm -rf avl-tree

.PHONY: clean
