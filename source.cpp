#include <iostream>
#include <stdexcept>

namespace Handmade {
    template<typename T, std::size_t N>
    class Array final {
        using value_type = T;
  
        using reference = value_type&;
        using const_reference = const value_type&;

        using size_type = std::size_t;
  
        using pointer = value_type*;
        using const_pointer = const value_type*;
  
        size_type m_size;
        size_type m_size_max;
  
        T m_arr[N];
    public:
        explicit Array(const std::initializer_list<value_type> &list) : m_size(list.size()), m_size_max(N) {
            if(m_size > m_size_max) { 
                throw std::length_error("data sheet size is larger than acceptable range");
            }

            for(size_type i{}; i < m_size; ++i){ 
                m_arr[i] = *(list.begin() + i); 
            }
        }

        explicit Array(const Array<value_type, N>& other) : m_size(0), m_size_max(N) {
            *this = other;
        }

        Array() : m_size(0), m_size_max(0) {};

        Array<value_type, N> operator=(const Array<value_type, N>& other) {
            *this = other;
        }

        //operator

        reference operator[](const size_type pos) {
            return m_arr[pos];
        }

        bool operator==(const Array<value_type, N>& other) const {
            if(m_size != other.m_size_max){
                return false;
            }
            for(size_type i{}; i < m_size_max; ++i){
                if(m_arr[i] != other.m_arr[i]){
                    return false;
                }
            }
            return true;
        }
  
        const_reference operator[](const size_type pos)const {
            return m_arr[pos];
        }

        // no-const function
  
        reference front() {
            return m_arr[0];
        }

        reference back() {
            return m_arr[m_size_max - 1];
        }

        reference at(const size_type pos) {
            if(pos >= m_size_max){
                throw std::out_of_range("incorrect index for obtaining a resource");
            } 

            return m_arr[pos];
        }

        void fill(const value_type& value) {
            for(auto& item : m_arr) {
                item = value;
            }
        }

        pointer data() noexcept {
            return m_arr;
        }

        void swap(Array<value_type, N>& other) noexcept {
            Array<value_type, N> temporary_array = *this;
            *this = other;
            other = temporary_array;
        }

        //const function

        const_reference front()const {
            return m_arr[0];
        }

        const_reference back()const {
            return m_arr[m_size_max - 1];
        }

        const_reference at(const size_type pos)const {
            if(pos >= m_size_max){
                throw std::out_of_range("incorrect index for obtaining a resource");
            } 

            return m_arr[pos];
        }

        size_type size()const {
            return m_size;
        }

        bool empty()const {
            return m_size == 0 ? true : false;
        }

        const_pointer data() const {
            return m_arr;
        }

        ~Array() = default;
    };

  template<std::size_t I, typename T, std::size_t N>
  T& get(Array<T,N>& a) noexcept {
    return a[I];
  }
  
  template<std::size_t I, typename T, std::size_t N>
  const T& get(const Array<T,N>& a) noexcept {
    return a[I];
  }
}

int main()
{
    Handmade::Array<int, 3> arr{100,200,400};
    Handmade::get<0>(arr) = 10;
    std::cout << Handmade::get<0>(arr) << std::endl;
    return 0;
}