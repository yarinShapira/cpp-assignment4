#include "FootSoldier.hpp"


void FootSoldier::activity(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location){
    std::pair<int,int> location = search(board, location, this->get_player());
    if (location.first != -1){
        board[location.first][location.second]->injured(this->_DP);
    }
}
std::pair<int,int> search(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number){
    std::pair<int,int> location_0 = search_UP(board, location, player_number);
    std::pair<int,int> location_1 = search_Right(board, location, player_number);
    std::pair<int,int> location_2 = search_Left(board, location, player_number);
    std::pair<int,int> location_3 = search_Down(board, location, player_number);
    int min;
    int temp;
    std::pair<int,int> to_return;
    if (location_0.first == -1 && location_2.first == -1 && location_3.first == -1) return location_0;
    if (location_0.first == -1 && location_2.first == -1 && location_3.first == -1) return location_1;
    if (location_0.first == -1 && location_1.first == -1 && location_3.first == -1) return location_2;
    if (location_0.first == -1 && location_1.first == -1 && location_2.first == -1) return location_3;
    if (location_0.first == -1 && location_1.first == -1){
        min = (abs(location_2.first - location.first)) + (abs(location_2.second - location.second));
        temp = (abs(location_3.first - location.first)) + (abs(location_3.second - location.second));
        if (temp < min) return location_2;
        return location_3;
    }
    if (location_0.first == -1 && location_2.first == -1){
        min = (abs(location_1.first - location.first)) + (abs(location_1.second - location.second));
        temp = (abs(location_3.first - location.first)) + (abs(location_3.second - location.second));
        if (temp < min) return location_1;
        return location_3;
    }
    if (location_0.first == -1 && location_3.first == -1){
        min = (abs(location_1.first - location.first)) + (abs(location_1.second - location.second));
        temp = (abs(location_2.first - location.first)) + (abs(location_2.second - location.second));
        if (temp < min) return location_1;
        return location_2;
    }
    if (location_1.first == -1 && location_2.first == -1){
        min = (abs(location_0.first - location.first)) + (abs(location_0.second - location.second));
        temp = (abs(location_3.first - location.first)) + (abs(location_3.second - location.second));
        if (temp < min) return location_0;
        return location_3;
    }
    if (location_1.first == -1 && location_3.first == -1){
        min = (abs(location_0.first - location.first)) + (abs(location_0.second - location.second));
        temp = (abs(location_2.first - location.first)) + (abs(location_2.second - location.second));
        if (temp < min) return location_0;
        return location_2;
    }
    if (location_2.first == -1 && location_3.first == -1){
        min = (abs(location_0.first - location.first)) + (abs(location_0.second - location.second));
        temp = (abs(location_1.first - location.first)) + (abs(location_1.second - location.second));
        if (temp < min) return location_0;
        return location_1;
    }
    if (location_0.first == -1){
        min = (abs(location_1.first - location.first)) + (abs(location_1.second - location.second));
        to_return = location_1;
        temp = (abs(location_2.first - location.first)) + (abs(location_2.second - location.second));
        if (temp < min){
            min = temp;
            to_return = location_2;
        }
        temp = (abs(location_3.first - location.first)) + (abs(location_3.second - location.second));
        if (temp < min){
            min = temp;
            to_return = location_3;
        }
        return to_return;
    }
    if (location_1.first == -1){
        min = (abs(location_0.first - location.first)) + (abs(location_0.second - location.second));
        to_return = location_0;
        temp = (abs(location_2.first - location.first)) + (abs(location_2.second - location.second));
        if (temp < min){
            min = temp;
            to_return = location_2;
        }
        temp = (abs(location_3.first - location.first)) + (abs(location_3.second - location.second));
        if (temp < min){
            min = temp;
            to_return = location_3;
        }
        return to_return;
    }
    if (location_2.first == -1){
        min = (abs(location_0.first - location.first)) + (abs(location_0.second - location.second));
        to_return = location_0;
        temp = (abs(location_1.first - location.first)) + (abs(location_1.second - location.second));
        if (temp < min){
            min = temp;
            to_return = location_1;
        }
        temp = (abs(location_3.first - location.first)) + (abs(location_3.second - location.second));
        if (temp < min){
            min = temp;
            to_return = location_3;
        }
        return to_return;
    }
    if (location_3.first == -1){
        min = (abs(location_0.first - location.first)) + (abs(location_0.second - location.second));
        to_return = location_0;
        temp = (abs(location_1.first - location.first)) + (abs(location_1.second - location.second));
        if (temp < min){
            min = temp;
            to_return = location_1;
        }
        temp = (abs(location_2.first - location.first)) + (abs(location_2.second - location.second));
        if (temp < min){
            min = temp;
            to_return = location_2;
        }
        return to_return;
    }
    min = (abs(location_0.first - location.first)) + (abs(location_0.second - location.second));
    to_return = location_0;
    temp = (abs(location_1.first - location.first)) + (abs(location_1.second - location.second));
    if (temp < min){
        min = temp;
        to_return = location_1;
    }
    temp = (abs(location_2.first - location.first)) + (abs(location_2.second - location.second));
    if (temp < min){
        min = temp;
        to_return = location_2;
    }
    temp = (abs(location_3.first - location.first)) + (abs(location_3.second - location.second));
    if (temp < min){
        min = temp;
        to_return = location_3;
    }
    return to_return;
}

std::pair<int,int> search_UP(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number){
    if (location.first + 1 < board.size()){
        if (board[location.first][location.second] != nullptr){
            if (board[location.first + 1][location.second]->get_player() != player_number){
                return  std::pair<int,int>{location.first + 1, location.second};
            }
            return search_UP(board, std::pair<int,int>{location.first + 1, location.second}, player_number); 
        }
        return search_UP(board, std::pair<int,int>{location.first + 1, location.second}, player_number);
    }
    return std::pair<int,int>{-1,-1};
}
std::pair<int,int> search_Down(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number){
    if (location.first - 1 > -1) {
        if (board[location.first][location.second] != nullptr){
            if (board[location.first - 1][location.second]->get_player() != player_number){
                return  std::pair<int,int>{location.first - 1, location.second};
            }
            return search_Down(board, std::pair<int,int>{location.first - 1, location.second}, player_number); 
        }
        return search_Down(board, std::pair<int,int>{location.first - 1, location.second}, player_number);
    }
    return std::pair<int,int>{-1,-1};
}
std::pair<int,int> search_Right(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number){
    if (location.second + 1 < board[location.first].size()){
        if (board[location.first][location.second + 1] != nullptr){
            if (board[location.first][location.second + 1]->get_player() != player_number){
                return  std::pair<int,int>{location.first, location.second + 1};
            }
        }
        std::pair<int,int> a = search_UP(board, std::pair<int,int>{location.first, location.second + 1}, player_number);
        std::pair<int,int> b = search_Right(board, std::pair<int,int>{location.first, location.second + 1}, player_number);
        std::pair<int,int> c = search_Down(board, std::pair<int,int>{location.first, location.second + 1}, player_number);
        int min;
        int temp;
        std::pair<int,int> to_return;
        if (a.first == -1 && b.first == -1) return c;
        if (a.first == -1 && c.first == -1) return b;
        if (b.first == -1 && c.first == -1) return a;
        if (a.first == -1){
            min = (abs(b.first - location.first)) + (abs(b.second - location.second));
            temp = (abs(c.first - location.first)) + (abs(c.second - location.second));
            if (temp < min){
                return c;
            }
            return b;
        }
        if (b.first == -1){
            min = (abs(a.first - location.first)) + (abs(a.second - location.second));
            temp = (abs(c.first - location.first)) + (abs(c.second - location.second));
            if (temp < min){
                return c;
            }
            return a;
        }
        if (c.first == -1){
            min = (abs(a.first - location.first)) + (abs(a.second - location.second));
            temp = (abs(b.first - location.first)) + (abs(b.second - location.second));
            if (temp < min){
                return b;
            }
            return a;
        }
        min = (abs(a.first - location.first)) + (abs(a.second - location.second));
        to_return = a;
        temp = (abs(b.first - location.first)) + (abs(b.second - location.second));
        if (temp < min){
            min = temp;
            to_return = b;
        }
        temp = (abs(c.first - location.first)) + (abs(c.second - location.second));
        if (temp < min){
            min = temp;
            to_return = c;
        }
        return to_return;
    }
    return std::pair<int,int>{-1,-1};
}

std::pair<int,int> search_Left(std::vector<std::vector<Soldier*>> board, std::pair<int,int> location, int player_number){
        if (location.second - 1 > -1){
        if (board[location.first][location.second - 1] != nullptr){
            if (board[location.first][location.second - 1]->get_player() != player_number){
                return  std::pair<int,int>{location.first, location.second - 1};
            }
        }
        std::pair<int,int> a = search_UP(board, std::pair<int,int>{location.first, location.second - 1}, player_number);
        std::pair<int,int> b = search_Right(board, std::pair<int,int>{location.first, location.second - 1}, player_number);
        std::pair<int,int> c = search_Down(board, std::pair<int,int>{location.first, location.second - 1}, player_number);
        int min;
        int temp;
        std::pair<int,int> to_return;
        if (a.first == -1 && b.first == -1) return c;
        if (a.first == -1 && c.first == -1) return b;
        if (b.first == -1 && c.first == -1) return a;
        if (a.first == -1){
            min = (abs(b.first - location.first)) + (abs(b.second - location.second));
            temp = (abs(c.first - location.first)) + (abs(c.second - location.second));
            if (temp < min){
                return c;
            }
            return b;
        }
        if (b.first == -1){
            min = (abs(a.first - location.first)) + (abs(a.second - location.second));
            temp = (abs(c.first - location.first)) + (abs(c.second - location.second));
            if (temp < min){
                return c;
            }
            return a;
        }
        if (c.first == -1){
            min = (abs(a.first - location.first)) + (abs(a.second - location.second));
            temp = (abs(b.first - location.first)) + (abs(b.second - location.second));
            if (temp < min){
                return b;
            }
            return a;
        }
        min = (abs(a.first - location.first)) + (abs(a.second - location.second));
        to_return = a;
        temp = (abs(b.first - location.first)) + (abs(b.second - location.second));
        if (temp < min){
            min = temp;
            to_return = b;
        }
        temp = (abs(c.first - location.first)) + (abs(c.second - location.second));
        if (temp < min){
            min = temp;
            to_return = c;
        }
        return to_return;
    }
    return std::pair<int,int>{-1,-1};
}

FootSoldier::~FootSoldier(){

}