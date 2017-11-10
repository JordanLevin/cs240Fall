#include <iostream>


void recurse(int n, int val){
    if(n == 0)
        return;
    recurse(n-1, val*3);
    std::cout << val << '\n';
}

int main(int argc, char *argv[]){
    //I could totally make this take 1 parameter with a helper
    //but this works and the assignment didnt specify
    recurse(5, 3);
    return 0;
}

