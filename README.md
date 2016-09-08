# libTreeSim

A free library made with freeglut to simulate binary trees from command line programs written in c/c++.<br>
Uses pthread, freeglut, openGl,... etc <br>

#Usage
Default structure should be like this :<br>
<code><pre>
typedef struct bintree
{
	item d;
	struct bintree *l;
	struct bintree *r;
} tree;
</code></pre>

To initialize :
<code><pre>
init(&bst);
</code></pre>

To redraw current state of binary tree
<code><pre>
redraw();
</code></pre>
