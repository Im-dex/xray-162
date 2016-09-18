#pragma once

// 1. class or not class
template<typename T>
struct	is_class {
    static constexpr auto result = std::is_class<T>::value;
};

template<typename T>	
struct	is_polymorphic {
    static constexpr auto result = std::is_polymorphic_v<T>;
};
