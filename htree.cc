/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"
#include <memory>
//#include <iostream>

HTree::HTree(key_t key, value_t value, tree_ptr_t left, tree_ptr_t right){
	key_ = key;
	value_ = value;
	left_ = left;
	right_ = right;
}

HTree::key_t HTree::get_key() const{
	return key_;
}

// Return value in current node
HTree::value_t HTree::get_value() const{
	return value_;
}      

// Return the child of this node indicated by dir.
// If the child is nullptr (current node is a leaf), returns nullptr.
HTree::tree_ptr_t HTree::get_child(Direction dir) const{
	switch(dir){
		case HTree::Direction::LEFT:
			return left_;
			break;
		case HTree::Direction::RIGHT:
			return right_;
			break;
		default:
			return nullptr;
	}
}

/*
bool path_finder(const HTree::tree_ptr_t root, const HTree::key_t key, HTree::path_t& path){
	std::cout << "searching current root " << root->get_key() << std::endl;
	if(root->get_key() == key){
		std::cout << "found key" << std::endl;
		return true;
	}else{
		if(root->get_child(HTree::Direction::LEFT)){	//prevent dereferencing nullptr
			if(path_finder(root->get_child(HTree::Direction::LEFT), key, path)){
				path.push_front(HTree::Direction::LEFT);
				return true;
			} else{
				if(root->get_child(HTree::Direction::RIGHT)){	//prevent dereferencing nullptr
					if(path_finder(root->get_child(HTree::Direction::RIGHT), key, path)){
						path.push_front(HTree::Direction::RIGHT);
						return true;
					} else{
						return false;
					}
				}
			}
		}
	}
}
*/


bool path_finder(const HTree::tree_ptr_t root, const HTree::key_t key, HTree::path_t& path){
//	std::cout << "searching current root " << root->get_key() << std::endl;
	if(root->get_key() == key){
//		std::cout << "found key" << std::endl;
		return true;
	}else{
		if(root->get_child(HTree::Direction::LEFT)){
			if(path_finder(root->get_child(HTree::Direction::LEFT), key, path)){
				path.push_front(HTree::Direction::LEFT);
				return true;
			}
		}
		if(root->get_child(HTree::Direction::RIGHT)){
			if(path_finder(root->get_child(HTree::Direction::RIGHT), key, path)){
				path.push_front(HTree::Direction::RIGHT);
				return true;
			}
		}
	return false;
	}
}


// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr
HTree::possible_path_t HTree::path_to(key_t key) const{
//	return nullptr;
	HTree::path_t path = { };
	HTree badInefficientCopy = *this;
	auto root = std::make_shared<HTree>(badInefficientCopy);
	if(path_finder(root, key, path)){
		return std::make_unique<HTree::path_t>(path);
	} else{
		return nullptr;
	}
}



//make 2&>1 | less