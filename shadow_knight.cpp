#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class ShadowKnight {
  public:
    ShadowKnight(uint32_t, uint32_t, uint32_t, uint32_t);

  void BinaryJump(std::string);

  void Print();

  private:
    bool inputFlag_ = false;
  uint32_t column_ = 0, row_ = 0;
  uint32_t right_ = 0, bottom_ = 0, left_ = 0, top_ = 0;
  std::vector < std::vector < char >> building_;
};

// constructor to initialize vector inside vector to form building windows
ShadowKnight::ShadowKnight(uint32_t width, uint32_t hight, uint32_t startColumn, uint32_t startRow)
  // as vector index starts with 0 so right and bottom one less form respective fields
  : right_(width - 1U), bottom_(hight - 1U), column_(startColumn), row_(startRow) {
    building_.reserve(hight);
    for (uint32_t i = 0; i < hight; i++) {
      std::vector < char > horizontal(width, '-'); //temporary vector initialzed with, width size and '-' data.
      building_.push_back(horizontal);
    }

    // '@' shows current position of batman
    building_[startRow][startColumn] = '@';
    Print();
    std::cout << "At Starting Batman at window (" << column_ << "," << row_ << ")" << std::endl;
  }

void ShadowKnight::Print() {

  std::cout << std::endl;
  for (uint32_t i = 0; i < building_.size(); i++) {
    for (uint32_t j = 0; j < building_[i].size(); j++) {
      std::cout << building_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

// implemented binary search algorithm on 2d array.
void ShadowKnight::BinaryJump(std::string bombDir) {
  if ((bombDir.find('L') != std::string::npos) && (column_ > 0)) {
    right_ = column_ - 1U;
    inputFlag_ = true;
  }
  if (bombDir.find('R') != std::string::npos) {
    left_ = column_ + 1U;
    inputFlag_ = true;
  }
  if ((bombDir.find('U') != std::string::npos) && (row_ > 0)) {
    bottom_ = row_ - 1U;
    inputFlag_ = true;
  }
  if (bombDir.find('D') != std::string::npos) {
    top_ = row_ + 1U;
    inputFlag_ = true;
  }

  if (inputFlag_ == true) {
    building_[row_][column_] = '-';
    row_ = (top_ + bottom_) / 2U; // suffix U is used for unsigned number
    column_ = (left_ + right_) / 2U;
    building_[row_][column_] = '@';
    Print();
    inputFlag_ = false;
    std::cout << "Batman jumped to window (" << column_ << "," << row_ << ")" << std::endl;
  } else {
    std::cerr << "Invalid hint! Plz give hint from mentioned in bracket only" << std::endl;
  }

}

int main() {
  std::cout << "### Locate the bomb, save the hostages ###" << std::endl;

  std::cout << "Enter width and hight of building: " << std::endl;
  uint32_t width; // width of the building.
  uint32_t hight; // height of the building.
  std::cin >> width >> hight;
  std::cin.ignore();

  std::cout << "Enter column and row in order, to specify initial position of Batman: " << std::endl;
  uint32_t startColumn;
  uint32_t startRow;
  std::cin >> startColumn >> startRow;
  std::cin.ignore();

  // created object of shadow knight class
  ShadowKnight shadowObj(width, hight, startColumn, startRow);

  uint16_t trials = log2(width * hight); // worst case time complexity of binary search is o(log2n)
  std::cout << "Max num of hints allowed to locate the bomb is: " << trials << std::endl;

  std::cout << "Give hint of direction as specified in bracket (U, UR, R, DR, D, DL, L, UL): " << std::endl;

  uint16_t i = 0;
  // game loop
  while (i <= trials) {
    std::string bombDir; // the direction of the bombs from batman's current location
    std::cin >> bombDir;
    std::cin.ignore();

    shadowObj.BinaryJump(bombDir);
    i++;
  }
}