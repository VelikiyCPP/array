#include <iostream>
#include <stdexcept>

namespace Handmade {
    template<typename T, std::size_t N>
    class Array final {
        std::size_t mSize;
        T arr[N];
    public:
        explicit Array(const std::initializer_list<T> &list) {
            if(list.size() > N) { 
                throw std::length_error("data sheet size is larger than acceptable range");
            }
            
            for(std::size_t i{}; i < list.size(); ++i){ 
                arr[i] = *(list.begin() + i); 
            } 
        }
        
        Array() {}
        
        T front()const {
            return arr[0];
        }
        
        T back()const {
            return arr[N - 1];
        }
        
        T at(std::size_t pos)const {
            if(pos >= N){
                throw std::out_of_range("incorrect index for obtaining a resource");
            } 
            
            return arr[pos];
        }
        
        T operator[](std::size_t pos)const {
            return arr[pos];
        }
        
        std::size_t getSize()const {
            return mSize;
        }
        
        bool isEmpty()const {
            return static_cast<bool>(!mSize);
        }
        
        void fill(const T& data) {
            for(auto& item : arr) {
                item = data;
            }
        }
        
        T* data() noexcept {
            return arr;
        }
        
        const T* data() const noexcept {
            return arr;
        }
    };
}

int main()
{
    Handmade::Array<int, 3> arr{100,200,400};
    std::cout << *(arr.data() + 2) << std::endl;
    return 0;
}