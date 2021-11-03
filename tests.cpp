enum class Direction {LEFT, RIGHT};

int main(){
	Direction dir = Direction::LEFT;
	Direction dir2 = Direction::RIGHT;
	switch(dir){
		case Direction::LEFT:
			std::cout << "is left" << std::endl;
			break;
		case Direction::RIGHT:
			std::cout << "is right" << std::endl;
			break;
		default:
	}
	return 0;
}