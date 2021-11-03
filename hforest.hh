#include <memory>
#include "htree.hh"
#include <algorithm>
#include <vector>

class HForest {
	public:
		HForest();
		~HForest() = default;

		int size() const;
		void add_tree(HTree::tree_ptr_t tree) const;
		HTree::tree_ptr_t pop_tree() const;
	private:
		std::vector<HTree::tree_ptr_t> forest {};
		bool treeCompare(HTree::tree_ptr_t tree1, HTree::tree_ptr_t tree2) const;
};