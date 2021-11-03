#include "hforest.hh"

HForest::HForest(){

}

int HForest::size() const{
	return forest.size();
}

bool HForest::treeCompare(HTree::tree_ptr_t tree1, HTree::tree_ptr_t tree2) const{
	return (tree1->get_value() < tree2->get_value());
}

void HForest::add_tree(HTree::tree_ptr_t tree) const{
	forest.push_back(tree);
	std::make_heap(forest.begin(), forest.end(), treeCompare());
}

HTree::tree_ptr_t HForest::pop_tree() const{

}