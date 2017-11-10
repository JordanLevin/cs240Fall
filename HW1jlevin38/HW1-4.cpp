#include <string>
#include <iostream>
#include <vector>

class Team{
    public:
        std::string name;
        unsigned int wins, losses;

        Team(std::string n, int w, int l){
            name = n;
            wins = w;
            losses = l;
        }

        bool operator<(const Team& other){
            float f = wins/(wins+losses);
            float f2 = other.wins/(other.wins+other.losses);
            return f < f2;
        }

};

template<typename T>
std::vector<T> merge(std::vector<T> v1, std::vector<T> v2){
    auto i1 = v1.begin();
    auto i2 = v2.begin();
    std::vector<T> ret;
    while(i1 != v1.end() || i2 != v2.end()){
        if(i1 == v1.end()){
            ret.push_back(*i2);
            i2++;
        }
        else if(i2 == v2.end()){
            ret.push_back(*i1);
            i1++;
        }
        else if(*i1 < *i2){
            ret.push_back(*i1);
            i1++;
        }
        else{
            ret.push_back(*i2);
            i2++;
        }
    }
    return ret;
}

template<typename T>
std::vector<T> merge_sort(std::vector<T> v1){
    if(v1.size() <= 1)
        return v1;
    std::size_t v1_half = v1.size()/2;
    std::vector<T> v1_lower(v1.begin(), v1.begin() + v1_half);
    std::vector<T> v1_upper(v1.begin() + v1_half, v1.end());
    return merge(merge_sort(v1_lower), merge_sort(v1_upper));
}


int main(int argc, char *argv[]){
    std::vector<int> test = {6,4,2,7,8,2,5,9,1};
    for (int i = 0; i < test.size(); ++i) {
        std::cout << test[i] << " ";
    }
    std::cout << '\n';

    std::vector<int> sorted = merge_sort(test);
    std::cout << "sorted: " << std::endl;
    for (int i = 0; i < sorted.size(); ++i) {
        std::cout << sorted[i] << " ";
    }
    std::cout << '\n' << std::endl;
    return 0;
}
