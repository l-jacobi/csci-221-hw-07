hTree.hh defines a class HTree with variables key_ and value_, and pointers to its branch trees
left_ and right_. It has four methods which are defined in htree.cc:
	get_key and value_ : these simply return key_ and value_ respectively.
	get_child : uses a switch to return either the left or right branches if they are asked for,
	and otherwise returns nullptr.
	path_to : this creates a path in the form of a std::list of directions to a node from the
	root of the tree it is called on, and returns a unique pointer to the path. path_to creates a
	copy of the object it is finding a path for and runs the helper function path_finder on it.
	This is not exactly ideal as it has increased performance cost with larger lists, however, a
	shared pointer could not be copied to path_finder as it would create ownership issues, and
	path_finder could possibly then delete the data, which would be less ideal. There is likely a
	better solution in general, but I was too attatched to my path_finder function to redo
	everything else here.
	path_finder works by recursively iterating through all tree nodes until the key has been
	found. The function returns a boolean, which represent whether or not the key has been found
	yet. The function checks if the current node is the key it is looking for and returns true if
	it is. If not, it checks if there is a left branch of the current root, and if so runs the
	fuction on that, treating it as the new root of the tree it is searching. When it comes to a
	node with no branches, it returns false, and so the second check for the right branch begins,
	where it does the same procedure.
	A shorter way of putting this is tThe function essentially recurses through all left branches
	until it meets a dead end, goes back to the last possible place to branch right, and repeats.

test_htree.cc creates and tests a tree which looks like this:

				126(1)
			/			\
		14(2)			25(3)
		/	\			/	\
	34(4)	2(5)	98(6)	97(7)
	/				/			\
36(8)			70(9)			23(10)
				/	\				\
			11(11)	27(12)			8(13)
The program crashes if you search for a key which is not in the tree, which is due to a
limitation of the testing's sophistication and not of htree.cc's, as the path_to method is
supposed to return a nullptr if it cannot find a path, and the testing dereferences the possible
path.

