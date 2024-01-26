avl-tree:
	g++ -o avl-tree main.cpp AVLTree.cpp -O3

test: avl-tree
	./avl-tree 10000000

bench:
	g++ -o bench bench.cpp AVLTree.cpp -O3
	./bench | tee results.txt

clean:
	rm -rf avl-tree bench results.txt

.PHONY: clean
