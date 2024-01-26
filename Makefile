avl-tree:
	g++ -o avl-tree *.cpp -O3

test: avl-tree
	./avl-tree 10000000

clean:
	rm -rf avl-tree

.PHONY: clean
